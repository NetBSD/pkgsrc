# $NetBSD: Makefile,v 1.23 2008/12/19 23:58:18 hira Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-session-${XFCE4_VERSION}
PKGREVISION=		2
CATEGORIES=		x11
COMMENT=		Xfce session manager

EGDIR=			${XFCE4_EGBASE}/session
CONF_FILES=		${EGDIR:Q}/xfce4-session.rc \
			${PKG_SYSCONFDIR:Q}/xdg/xfce4-session/xfce4-session.rc
CONF_FILES+= ${PREFIX}/share/xdg/autostart/xfce4-tips-autostart.desktop \
	     ${PKG_SYSCONFDIR:Q}/xdg/autostart/xfce4-tips-autostart.desktop

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	ICEAUTH=${TOOLS_PATH.iceauth:Q}

REQD_DIRS+=		${XFCE4_EGBASE} ${EGDIR} ${PREFIX}/share/xdg/autostart
BUILD_DEFS+=		PKG_SYSCONFBASE

OWN_DIRS+=              ${PKG_SYSCONFDIR}/xdg
OWN_DIRS+=              ${PKG_SYSCONFDIR}/xdg/xfce4-session
OWN_DIRS+=              ${PKG_SYSCONFDIR}/xdg/autostart

USE_TOOLS+=		iceauth:run
USE_DIRS+=		xdg-1.4

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
