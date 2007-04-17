# $NetBSD: Makefile,v 1.20 2007/04/17 17:45:07 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-session-${XFCE4_VERSION}
CATEGORIES=		x11
COMMENT=		Xfce session manager

PKG_SYSCONFSUBDIR=	xdg/xfce4-session
EGDIR=			${XFCE4_EGBASE}/session
CONF_FILES=		${EGDIR:Q}/xfce4-session.rc \
			${PKG_SYSCONFDIR:Q}/xfce4-session.rc

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
CONFIGURE_ARGS+=	ICEAUTH=${TOOLS_PATH.iceauth:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR}
BUILD_DEFS+=		PKG_SYSCONFBASE

USE_TOOLS+=		iceauth:run
USE_DIRS+=		xdg-1.4

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
