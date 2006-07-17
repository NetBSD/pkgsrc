# $NetBSD: Makefile,v 1.29 2006/07/17 17:06:59 joerg Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	xorg-imake-${XORG_VER}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R${XORG_VER}-src1.tar.gz X11R${XORG_VER}-src3.tar.gz

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	Imake and other utilities from X.org

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_DIRS+=		xorg-1.1
INSTALL_TARGET=		install install.man
NO_XORG_TARGETS=	yes

USE_TOOLS+=	perl:run
REPLACE_PERL+=	config/util/mkhtmlindex.pl

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
		-e "s|@@DARWIN_USE_QUARTZ@@|${DARWIN_USE_QUARTZ}|g"	\
		${WRKSRC}/config/cf/${F}.cf.in > ${WRKSRC}/config/cf/${F}.cf
.endfor
.undef F
	@( \
	${ECHO} "#define XORG_VERSION_MAJOR  6";	\
	${ECHO} "#define XORG_VERSION_MINOR  9";	\
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
	cd ${WRKSRC} && ${MAKE_PROGRAM} Makefile.boot &&	\
	${MAKE_PROGRAM} -f xmakefile VerifyOS version.def Makefiles includes

pre-install:
	@${CP} ${WRKSRC}/xmakefile ${WRKSRC}/xmakefile.bak
	@${SED} 's/SUBDIRS = include/SUBDIRS =/' ${WRKSRC}/xmakefile.bak > \
		${WRKSRC}/xmakefile

post-install:
	${CHMOD} ${NONBINMODE} ${X11ROOT}/lib/X11/config/host.def
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

.if !empty(MACHINE_PLATFORM:MNetBSD-1.6[M-Z]*) ||	\
    !empty(MACHINE_PLATFORM:MNetBSD-[2-9]*)
.  if exists(/usr/include/threadlib.h)
SUBST_CLASSES+=		thr
SUBST_STAGE.thr=	post-patch
SUBST_FILES.thr=	config/cf/NetBSD.cf.in
SUBST_SED.thr=		-e 's|@@NETBSD_THREADLIB@@|-DUSE_NBSD_THREADLIB|'
SUBST_MESSAGE.thr=	Fixes for threadlib.h.
.  else
SUBST_CLASSES+=		nada
SUBST_STAGE.nada=	post-patch
SUBST_FILES.nada=	config/cf/NetBSD.cf.in
SUBST_SED.nada=		-e 's|@@NETBSD_THREADLIB@@||'
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
