# $NetBSD: Makefile,v 1.38 2018/08/22 09:47:21 wiz Exp $

DISTNAME=	fvwm-${FVWM_VER}
PKGREVISION=	9
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/
MASTER_SITES+=	http://www.fvwm.org/generated/icon_download/
DISTFILES+=	fvwm-${FVWM_VER}.tar.gz fvwm_icons.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Newer version of X11 Virtual window manager
LICENSE=	gnu-gpl-v2

#DEPENDS+=	xpmroot-2.*:../../x11/xpmroot

CONFLICTS=	fvwm1-[0-9]* fvwm2-[0-9]* metisse-[0-9]* xpmroot-[0-9]*
EXTRACT_ONLY=	${DISTNAME}.tar.gz
FVWM_VER=	2.6.5

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run tar

PLIST_SUBST+=		FVWM_VER=${FVWM_VER:Q}

INSTALLATION_DIRS+=	lib/X11/fvwm2
INSTALLATION_DIRS+=	lib/X11/fvwm2/pixmaps
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/lib/X11/fvwm2
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/lib/X11
CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.libXpm:Q}/include
CONFIGURE_ARGS+=	--with-imagepath=${PREFIX}/lib/X11/fvwm2/pixmaps:${X11BASE}/include/X11/bitmaps:${X11BASE}/include/X11/pixmaps

# We don't want to have CPP from the buildlink directory
CONFIGURE_ENV+=		ac_cv_path_FVWM_CPP=${CPP:Q}
# To avoid ${WRKDIR} is included in perl script
CONFIGURE_ENV+=         ac_cv_path_PERL=${PERL5:Q}

post-extract:
	mkdir ${WRKDIR}/icons
	cd ${WRKDIR}/icons && tar -xzf ${DISTDIR}/fvwm_icons.tgz

post-install:
	${INSTALL_DATA} \
		${WRKDIR}/icons/fvwm_icons/*.xpm \
		${DESTDIR}${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/decor_examples \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc-sample-* \
		${DESTDIR}${PREFIX}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${DESTDIR}${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example
	if [ ! -f ${DESTDIR}${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ]; then \
		${INSTALL_DATA} \
			${DESTDIR}${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example \
			${DESTDIR}${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ; \
	fi

.include "options.mk"

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
