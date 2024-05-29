# $NetBSD: Makefile,v 1.56 2024/05/29 16:35:16 adam Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.9.4
DISTNAME=	xfce4-notifyd-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-notifyd/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/apps/notifyd/start
COMMENT=	Xfce Notify daemon

USE_TOOLS+=	gdbus-codegen

CONFIGURE_ARGS+=	--disable-systemd
CONFIGURE_ARGS+=	--enable-xdg-autostart

DESKTOP_FILE=	xfce4-notifyd.desktop
EGDIR=		share/examples/xfce4-notifyd
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${EGDIR}/${DESKTOP_FILE} \
		${PKG_SYSCONFDIR}/xdg/autostart/${DESKTOP_FILE}

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.34.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
