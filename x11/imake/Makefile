# $NetBSD: Makefile,v 1.20 2005/09/28 20:52:28 rillig Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	imake-${XF_VER}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	XFree86-${XF_VER}-src-1.tgz XFree86-${XF_VER}-src-3.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Imake and other utilities from XFree86

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_DIRS+=		XFree86-1.1
INSTALL_TARGET=		install install.man
NO_XFREE86_TARGETS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	flex-[0-9]*:../../devel/flex
PLIST_SUBST+=	LNDIR=
.elif ${OPSYS} == "OpenBSD"
PLIST_SUBST+=	LNDIR="@comment "
.else
PLIST_SUBST+=	LNDIR=
.endif

.include "../../meta-pkgs/XFree86/Makefile.common"

post-extract:
.for F in ${SYSTEMS}
	@${MV} ${WRKSRC}/config/cf/${F}.cf ${WRKSRC}/config/cf/${F}.cf.in
.endfor
.undef F

pre-configure:
.for F in ${SYSTEMS}
	@${SED} -e "s|@@PKGSRC_CC@@|${CC}|g" \
		-e "s|@@PKGSRC_CPP@@|${CPP}|g" \
		-e "s|@@PKGSRC_CXX@@|${CXX}|g" \
		-e "s|@@PKGSRC_CFLAGS@@|${CFLAGS}|g" \
		${WRKSRC}/config/cf/${F}.cf.in > ${WRKSRC}/config/cf/${F}.cf
.endfor
.undef F

do-build:
	@${TOUCH} ${WRKSRC}/config/cf/version.def
	@${TOUCH} ${WRKSRC}/config/cf/date.def
	@${CP} ${FILESDIR}/xf86site.def ${WRKSRC}/config/cf
	@${SED} \
		-e "s|@PREFIX@|${X11ROOT}|g" \
		-e "s|@BLNK@|${BUILDLINK_DIR}|g" \
		-e "s|@LOCALBASE@|${LOCALBASE}|g " \
		-e "s|@MAKE@|${MAKE_PROGRAM}|" \
		${FILESDIR}/host.def > ${WRKSRC}/config/cf/host.def
	cd ${WRKSRC} && ${MAKE} Makefile.boot && \
	${MAKE_PROGRAM} -f xmakefile VerifyOS version.def Makefiles includes

post-install:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	hostdef=${X11ROOT:Q}/lib/X11/config/host.def;			\
	hosttmp=${WRKSRC:Q}/host.def.tmp;				\
	(${SED} -e "s|\#define ProjectRoot ${X11ROOT}||" "$${hostdef}";	\
	 ${ECHO} "";							\
	 ${ECHO} "#ifdef BeforeVendorCF";				\
	 ${ECHO} "#define ProjectRoot ${X11ROOT}";			\
	 ${ECHO} "#endif";						\
	)> "$${hosttmp}";						\
	${INSTALL_DATA} "$${hosttmp}" "$${hostdef}";			\
	${RM} -f "$${hosttmp}"

.include "../../mk/bsd.pkg.mk"
