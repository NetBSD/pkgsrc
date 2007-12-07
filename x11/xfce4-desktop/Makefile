# $NetBSD: Makefile,v 1.29 2007/12/07 19:43:26 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfdesktop-${XFCE4_VERSION}
PKGNAME=	xfce4-desktop-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce desktop background manager

PKG_SYSCONFSUBDIR=	xdg/xfce4/desktop
EGDIR=			${XFCE4_EGBASE}/desktop
CONF_FILES=		${EGDIR:Q}/menu.xml ${PKG_SYSCONFDIR:Q}/menu.xml
.for l in ca cs da de el es et eu fi fr he hu ja ko nl pl pt_BR ro ru sk sv \
	uk vi zh_TW
CONF_FILES+=		${EGDIR:Q}/menu.xml.${l:Q} \
			${PKG_SYSCONFDIR:Q}/menu.xml.${l:Q}
.endfor
CONF_FILES+=		${EGDIR:Q}/xfce-registered-categories.xml \
			${PKG_SYSCONFDIR:Q}/xfce-registered-categories.xml
.for l in ca cs de el es eu fi he hu ja nl pl pt_BR ro ru sk sv zh_CN zh_TW
CONF_FILES+=		${EGDIR:Q}/xfce-registered-categories.xml.${l:Q} \
			${PKG_SYSCONFDIR:Q}/xfce-registered-categories.xml.${l:Q}
.endfor

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

REQD_DIRS+=		${XFCE4_EGBASE:Q} ${EGDIR:Q}
BUILD_DEFS+=		PKG_SYSCONFBASE

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
