# $NetBSD: Makefile,v 1.42 2023/02/11 01:28:44 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.7.3
DISTNAME=	xfce4-notifyd-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-notifyd/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/apps/notifyd/start
COMMENT=	Xfce Notify daemon

USE_TOOLS+=	gdbus-codegen

DESKTOP_FILE=	xfce4-notifyd.desktop
EGDIR=		share/examples/xfce4-notifyd
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${EGDIR}/${DESKTOP_FILE} \
		${PKG_SYSCONFDIR}/xdg/autostart/${DESKTOP_FILE}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
