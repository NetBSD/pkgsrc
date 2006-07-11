# $NetBSD: Makefile,v 1.3 2006/07/11 09:05:35 rillig Exp $

DISTNAME=	fvwm-${FVWM_VER}
PKGREVISION=	3
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/
DISTFILES+=	fvwm-${FVWM_VER}.tar.gz fvwm_icons.tgz

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Newer version of X11 Virtual window manager

DEPENDS+=	xpmroot-2.*:../../x11/xpmroot

CONFLICTS=	fvwm1-[0-9]* fvwm2-[0-9]*
EXTRACT_ONLY=	${DISTNAME}.tar.gz
FVWM_VER=	2.4.19

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES
USE_TOOLS+=		perl:run

PLIST_SUBST+=		FVWM_VER=${FVWM_VER:Q}

INSTALLATION_DIRS+=	lib/X11/fvwm2
INSTALLATION_DIRS+=	lib/X11/fvwm2/pixmaps

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX:Q}/lib/X11/fvwm2
CONFIGURE_ARGS+=	--libexecdir=${PREFIX:Q}/lib/X11
CONFIGURE_ARGS+=	--with-xpm-includes=${XPMDIR:Q}/include
CONFIGURE_ARGS+=	--with-imagepath=${PREFIX:Q}/lib/X11/fvwm2/pixmaps:${X11BASE:Q}/include/X11/bitmaps:${X11BASE:Q}/include/X11/pixmaps

# We don't want to have CPP from the buildlink directory
CONFIGURE_ENV+=		ac_cv_path_FVWM_CPP=${CPP:Q}

post-extract:
	${MKDIR} ${WRKDIR:Q}/icons
	cd ${WRKDIR:Q}/icons && ${TAR} -xzf ${DISTDIR:Q}/fvwm_icons.tgz

post-install:
	${INSTALL_DATA} \
		${WRKDIR:Q}/icons/fvwm_icons/*.xpm \
		${PREFIX:Q}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} \
		${WRKSRC:Q}/sample.fvwmrc/decor_examples \
		${WRKSRC:Q}/sample.fvwmrc/system.fvwm2rc-sample-* \
		${PREFIX:Q}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC:Q}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX:Q}/lib/X11/fvwm2/system.fvwm2rc.example
	${INSTALL_SCRIPT} \
		${WRKSRC:Q}/utils/fvwmrc_convert \
		${PREFIX:Q}/bin/fvwmrc_convert
	if [ ! -f ${PREFIX:Q}/lib/X11/fvwm2/system.fvwm2rc ]; then \
		${INSTALL_DATA} \
			${PREFIX:Q}/lib/X11/fvwm2/system.fvwm2rc.example \
			${PREFIX:Q}/lib/X11/fvwm2/system.fvwm2rc ; \
	fi

.include "../../mk/bsd.prefs.mk"

.if defined(FVWM2_USE_GTK) && ${FVWM2_USE_GTK} == "YES"
.include "../../x11/gtk/buildlink3.mk"
PLIST_SUBST+=		GTK=""
.else
PLIST_SUBST+=		GTK="@comment "
CONFIGURE_ARGS+=	--without-gtk-prefix
.endif

.if defined(FVWM2_USE_RPLAY) && ${FVWM2_USE_RPLAY} == "YES"
.include "../../audio/rplay/buildlink3.mk"
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
