# $NetBSD: Makefile,v 1.10 2018/11/12 03:51:33 ryoon Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-control-center-${VERSION:R}.2
CATEGORIES=	sysutils

COMMENT=	MATE Control Center

BUILD_DEPENDS+=	itstool>=0:../../textproc/itstool

PKGCONFIG_OVERRIDE+=	capplets/keybindings/mate-keybindings.pc.in
PKGCONFIG_OVERRIDE+=	capplets/default-applications/mate-default-applications.pc.in
PKGCONFIG_OVERRIDE+=	libslab/libslab.pc.in
PKGCONFIG_OVERRIDE+=	libwindow-settings/mate-window-settings-2.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/menus/matecc.menu \
		${PKG_SYSCONFDIR}/xdg/menus/matecc.menu

.include "../../devel/glib2/schemas.mk"

.include "../../devel/libappindicator3/buildlink3.mk"
.include "../../x11/libmatekbd/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../wm/marco/buildlink3.mk"
.include "../../x11/mate-settings-daemon/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
