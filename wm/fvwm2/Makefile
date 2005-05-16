# $NetBSD: Makefile,v 1.43 2005/05/16 01:15:34 jlam Exp $

DISTNAME=	fvwm-${FVWM_VER}
PKGNAME=	fvwm2-${FVWM_VER}
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/
DISTFILES+=	fvwm-${FVWM_VER}.tar.gz fvwm_icons.tgz

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Newer version of X11 Virtual window manager

DEPENDS+=	xpmroot-2.*:../../x11/xpmroot

CONFLICTS=	fvwm1-* fvwm>=1
EXTRACT_ONLY=	${DISTNAME}.tar.gz
FVWM_VER=	2.4.19

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES
PKGSRC_USE_TOOLS+=	gtar

PLIST_SUBST+=		FVWM_VER=${FVWM_VER}

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/lib/X11/fvwm2
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/lib/X11
CONFIGURE_ARGS+=	--with-xpm-includes=${XPMDIR}/include
CONFIGURE_ARGS+=	--with-imagepath=${PREFIX}/lib/X11/fvwm2/pixmaps:${X11BASE}/include/X11/bitmaps:${X11BASE}/include/X11/pixmaps

# We don't want to have CPP from the buildlink directory
CONFIGURE_ENV+=		ac_cv_path_FVWM_CPP="${CPP}"

post-extract:
	${MKDIR} ${WRKDIR}/icons
	${GTAR} -xzf ${DISTDIR}/fvwm_icons.tgz -C ${WRKDIR}/icons

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} \
		${WRKDIR}/icons/fvwm_icons/*.xpm \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/decor_examples \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc-sample-* \
		${PREFIX}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example
	${INSTALL_SCRIPT} \
		${WRKSRC}/utils/fvwmrc_convert \
		${PREFIX}/bin/fvwmrc_convert
	if [ ! -f ${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ]; then \
		${INSTALL_DATA} \
			${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example \
			${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ; \
	fi

.include "../../mk/bsd.prefs.mk"

.if defined(FVWM2_USE_GTK) && ${FVWM2_USE_GTK} == "YES"
.include "../../x11/gtk/buildlink3.mk"
PLIST_SUBST+=	    GTK=""
.else
PLIST_SUBST+=	    GTK="@comment "
CONFIGURE_ARGS+=    --without-gtk-prefix
.endif

.if defined(FVWM2_USE_RPLAY) && ${FVWM2_USE_RPLAY} == "YES"
.include "../../audio/rplay/buildlink3.mk"
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
