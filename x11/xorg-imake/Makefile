# $NetBSD: Makefile,v 1.8 2004/08/04 06:49:41 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	xorg-imake-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R6.7.0-src1.tar.gz X11R6.7.0-src3.tar.gz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	Imake and other utilities from X.org

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		yes
USE_DIRS+=		xorg-1.1
INSTALL_TARGET=		install install.man
NO_XORG_TARGETS=	yes

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

.include "../../meta-pkgs/xorg/Makefile.common"

post-extract:
	@${TOUCH} ${WRKSRC}/config/cf/date.def
.for F in ${SYSTEMS}
	@${MV} ${WRKSRC}/config/cf/${F}.cf  ${WRKSRC}/config/cf/${F}.cf.in
.endfor
.undef F
	@${SED} -e "s|CONFIGDIRSPEC|-I${X11ROOT}/lib/X11/config|" \
		${WRKSRC}/config/util/xmkmf.cpp > \
		${WRKSRC}/config/util/xmkmf.cpp.orig
	@${MV} ${WRKSRC}/config/util/xmkmf.cpp.orig \
		${WRKSRC}/config/util/xmkmf.cpp

pre-configure:
.for F in ${SYSTEMS}
	@${SED} -e "s|@@PKGSRC_CC@@|${CC}|g"		\
		-e "s|@@PKGSRC_CPP@@|${CPP}|g"		\
		-e "s|@@PKGSRC_CXX@@|${CXX}|g"		\
		-e "s|@@PKGSRC_CFLAGS@@|${CFLAGS}|g"	\
		${WRKSRC}/config/cf/${F}.cf.in > ${WRKSRC}/config/cf/${F}.cf
.endfor
.undef F
	@( \
	${ECHO} "#define XORG_VERSION_MAJOR  6";	\
	${ECHO} "#define XORG_VERSION_MINOR  7";	\
	${ECHO} "#define XORG_VERSION_PATCH  0";	\
	${ECHO} "#define XORG_VERSION_SNAP   0";	\
	) > ${WRKSRC}/config/cf/version.def

do-build:
	@${CP} ${FILESDIR}/xorgsite.def ${WRKSRC}/config/cf
	@${SED} -e "s|@PREFIX@|${X11ROOT}|g"		\
		-e "s|@BLNK@|${BUILDLINK_DIR}|g"	\
		-e "s|@LOCALBASE@|${LOCALBASE}|g "	\
		-e "s|@MAKE@|${MAKE_PROGRAM}|"	${FILESDIR}/host.def > \
		${WRKSRC}/config/cf/host.def
	cd ${WRKSRC} && ${MAKE} Makefile.boot &&	\
	${MAKE_PROGRAM} -f xmakefile VerifyOS version.def Makefiles includes

pre-install:
	@${CP} ${WRKSRC}/xmakefile ${WRKSRC}/xmakefile.bak
	@${SED} 's/SUBDIRS = include/SUBDIRS =/' ${WRKSRC}/xmakefile.bak > \
		${WRKSRC}/xmakefile

post-install:
	@${CP} ${X11ROOT}/lib/X11/config/host.def		\
		${X11ROOT}/lib/X11/config/host.def.orig
	@${SED} -e "s|\#define ProjectRoot ${X11ROOT}||"	\
		${X11ROOT}/lib/X11/config/host.def.orig >	\
		${X11ROOT}/lib/X11/config/host.def
	@${RM} ${X11ROOT}/lib/X11/config/host.def.orig

	@( \
	${ECHO};					\
	${ECHO} "#ifdef BeforeVendorCF";		\
	${ECHO} "#define ProjectRoot ${X11ROOT}";	\
	${ECHO} "#endif";				\
	) >> ${X11ROOT}/lib/X11/config/host.def

.include "../../mk/bsd.pkg.mk"
