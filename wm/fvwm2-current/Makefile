# $NetBSD: Makefile,v 1.2 2001/04/27 15:14:58 zuntum Exp $
#

DISTNAME=	fvwm-${FVWM_VERSION}
PKGNAME=	fvwm2-${FVWM_VERSION}
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm_icons.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Popular virtual window manager for X

DEPENDS+=	xpmroot-2.*:../../x11/xpmroot
DEPENDS+=	readline-*:../../devel/readline
DEPENDS+=	rplay-3.*:../../audio/rplay

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

CONFLICTS=	fvwm-2.*

FVWM_VERSION=	2.3.31

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
PLIST_SUBST+=	VERSION=${FVWM_VERSION}

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--enable-extras
CONFIGURE_ARGS+=	--with-xpm-includes=${XPMDIR}/include
CONFIGURE_ARGS+=	--with-readline-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-rplay-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-iconpath=${PREFIX}/lib/X11/fvwm2/pixmaps:${X11BASE}/include/X11/bitmaps:${X11BASE}/include/X11/pixmaps

post-extract:
	cd ${WRKDIR} && ${MKDIR} icons && cd icons && \
		${GTAR} xfz ${_DISTDIR}/fvwm_icons.tgz

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} \
		${WRKDIR}/icons/*.xpm \
		${PREFIX}/lib/X11/fvwm2/pixmaps

.include "../../mk/bsd.pkg.mk"
