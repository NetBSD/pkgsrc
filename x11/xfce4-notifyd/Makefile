# $NetBSD: Makefile,v 1.32 2021/12/08 16:07:16 adam Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.6.2
DISTNAME=	xfce4-notifyd-${VERSION}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-notifyd/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-notifyd
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
