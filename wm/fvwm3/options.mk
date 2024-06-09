# $NetBSD: options.mk,v 1.5 2024/06/09 10:06:30 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fvwm3
PKG_SUPPORTED_OPTIONS=	doc go svg
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc go

#
# SVG icon support
#
.if !empty(PKG_OPTIONS:Msvg)
.  include "../../graphics/librsvg/buildlink3.mk"
.endif

#
# Build documentation (requires asciidoctor)
#
.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-mandoc
TOOL_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor
ASCIIDOC=               ${PREFIX}/bin/asciidoctor${RUBY_VER}
CONFIGURE_ENV+=		ac_cv_prog_ASCIIDOC=${ASCIIDOC:Q}
.  include "../../lang/ruby/rubyversion.mk"
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-mandoc
.endif

#
# Fvwm modules written in Go
#
.if !empty(PKG_OPTIONS:Mgo)

.  include "../../lang/go/version.mk"
.  include "go-modules.mk"

GO_BUILD_PATTERN?=	./...
GO_MOD_DIRS?=		bin/FvwmPrompt
GO_MOD_DOCS?=		FvwmPrompt

MAKE_JOBS_SAFE=		no
INSTALLATION_DIRS+=	bin
USE_TOOLS+=		pax

TOOL_DEPENDS+=		${GO_PACKAGE_DEP}
PRINT_PLIST_AWK+=	/^@pkgdir bin$$/ { next; }

MAKE_ENV+=	GO111MODULE=on GOPATH=${WRKDIR}/.gopath
MAKE_ENV+=	GOFLAGS=-ldflags="-s -w"
MAKE_ENV+=	GOPROXY=file://${WRKDIR}/.goproxy
MAKE_ENV+=	GOCACHE=${WRKDIR}/.cache/go-build
MAKE_ENV+=	GOTOOLCHAIN=local

.PHONY: show-go-modules
show-go-modules: ${WRKDIR}/.extract_done
.  for d in ${GO_MOD_DIRS}
	${RUN} cd ${WRKSRC}/${d} &&	\
		${PKGSRC_SETENV} ${MAKE_ENV} https_proxy= GOPROXY= ${GO} mod download -x
.  endfor
	${RUN} ${PRINTF} '# $$%s$$\n\n' NetBSD
	${RUN} cd ${WRKDIR}/.gopath/pkg/mod/cache/download &&	\
		${FIND} . -type f -a \( -name "*.mod" -o -name "*.zip" \)	\
	| ${SED} -e 's/\.\//GO_MODULE_FILES+=	/' | ${SORT}

DISTFILES?=		${DEFAULT_DISTFILES}
EXTRACT_ONLY?=		${DEFAULT_DISTFILES} ${GO_MODULE_EXTRACT}
.  for i in ${GO_MODULE_FILES}
DISTFILES+=		${i:C/[\/!]/_/g}
SITES.${i:C/[\/!]/_/g}=	-https://proxy.golang.org/${i}
.  endfor

post-extract:
.  for i in ${GO_MODULE_FILES}
	${RUN} ${MKDIR} ${WRKDIR}/.goproxy/${i:H}
	${RUN} cp ${DISTDIR}/${DIST_SUBDIR}/${i:C/[\/!]/_/g} ${WRKDIR}/.goproxy/${i}
.  endfor

post-build:
.  for d in ${GO_MOD_DIRS}
	${RUN} ${PRINTF} '%s\n' "Making fvwm Go modules in ${d} ... "
	${RUN} cd ${WRKSRC}/${d} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV}	\
		${GO} ${GOFLAGS} install -v ${GO_BUILD_PATTERN}
.  endfor
.  if !empty(PKG_OPTIONS:Mdoc)
.    for i in ${GO_MOD_DOCS}
	${RUN} ${PRINTF} '%s\n' "Building documentation for ${i} ... "
	${RUN} cd ${WRKSRC}/doc && ${ASCIIDOC} -b manpage -a ${i} ${i}.adoc -o ${i}.1
.    endfor
.  endif

post-install:
	${RUN} cd ${WRKDIR}/.gopath && [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}
.  for i in ${GO_MOD_DOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.  endfor

pre-clean:
	${RUN} [ -d ${WRKDIR}/.gopath ] && chmod -R +w ${WRKDIR}/.gopath ||  ${TRUE}

PLIST.go=		yes
.endif
