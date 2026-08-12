# $NetBSD: Makefile,v 1.3 2026/08/12 03:21:38 ryoon Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk90-${TK_VERSION}
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL (9.0 branch)
LICENSE=	2-clause-bsd

.include "version.mk"

WRKSRC=			${WRKDIR}/tk${TK_VERSION}

USE_GCC_RUNTIME=	yes

# use the same installation prefix as tcl since configure script
# says that otherwise it might not work
TK_SUBDIR=			tcl/9.0
.if !empty(TK_SUBDIR)
# Installation prefix is non-default.
# needed for parallel installation with lang/tk, which is 8.6
# and 9.0 and 8.6 are not completely compatible
# need to pass configure args manually, so don't set GNU_CONFIGURE
HAS_CONFIGURE=			yes
.  if !empty(TOOLS_USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=		--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
.  else
CONFIGURE_ARGS+=		--build=${MACHINE_GNU_PLATFORM:Q}
.  endif
CONFIGURE_ARGS+=		--host=${MACHINE_GNU_PLATFORM:Q}
TK_PREFIX=			${PREFIX}/${TK_SUBDIR}
CONFIGURE_ARGS+=		--prefix=${TK_PREFIX:Q}
CONFIGURE_ARGS+=		--infodir=${TK_PREFIX:Q}/info
CONFIGURE_ARGS+=		--mandir=${TK_PREFIX:Q}/man
BUILDLINK_PASSTHRU_DIRS+=	${TK_PREFIX}
LDFLAGS+=			${COMPILER_RPATH_FLAG}${TK_PREFIX}/lib
.else
GNU_CONFIGURE=			yes
TK_PREFIX=			${PREFIX}
.endif

# TODO: why is this necessary? Report upstream?
CFLAGS+=		-I${PREFIX}/${TCL90_SUBDIR}/include

CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_ARGS+=	--with-tcl=${_CROSS_DESTDIR:U}${BUILDLINK_PREFIX.tcl90}/${TCL90_SUBDIR}/lib

# xxx confusing arg to build tk zip file. man wish(1), zipfs(n)
CONFIGURE_ARGS+=	--disable-zipfs
CONFIGURE_ARGS+=	--enable-libcups=no

CONFIGURE_ENV+=		LIB_RUNTIME_DIR=${TK_PREFIX}/lib
PKGCONFIG_OVERRIDE+=	unix/tk.pc.in
USE_TOOLS+=		ln

# xxx whether tests pass, fail, or even complete seems window manager
# dependent and/or if mouse pointer/focus changes.  ctwm was able to
# finish and passed almost all of the tests for me
TEST_TARGET=		test

CHECK_PORTABILITY_SKIP=	win/configure

.include "options.mk"

SUBST_CLASSES+=		tk-config
SUBST_STAGE.tk-config=	post-build
SUBST_FILES.tk-config=	unix/tkConfig.sh
SUBST_SED.tk-config+=	-e "s|${WRKSRC}/unix|${TK_PREFIX}/lib|"
SUBST_SED.tk-config+=	-e "s|${WRKSRC}|${TK_PREFIX}/include/tk|"

PLIST_SUBST+=		SONUM=${TK_SONUM}
PLIST_SUBST+=		BASEVER=${TK_BASEVER}
PLIST_SUBST+=		VERSION=${TK_VERSION}

post-install:
	cd ${WRKSRC}/unix && ${MAKE} \
		BIN_INSTALL_DIR=${DESTDIR}${TK_PREFIX}/bin \
		LIB_INSTALL_DIR=${DESTDIR}${TK_PREFIX}/lib \
		CONFIG_INSTALL_DIR=${DESTDIR}${TK_PREFIX}/lib \
		SCRIPT_INSTALL_DIR=${DESTDIR}${TK_PREFIX}/lib/tk${TK_BASEVER} \
		INCLUDE_INSTALL_DIR=${DESTDIR}${TK_PREFIX}/include \
		PRIVATE_INCLUDE_DIR=${DESTDIR}${TK_PREFIX}/include \
		MAN_INSTALL_DIR=${DESTDIR}${TK_PREFIX}/${PKGMANDIR} \
		DEMO_INSTALL_DIR=${DESTDIR}${TK_PREFIX}/lib/tk${TK_BASEVER}/demos \
		install install-binaries
	cd ${DESTDIR}${TK_PREFIX}/bin && ${LN} -fs wish${TK_BASEVER} wish

.include "../../lang/tcl90/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
