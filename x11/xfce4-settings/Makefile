# $NetBSD: Makefile,v 1.46 2018/11/14 22:22:53 kleink Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.13.4
DISTNAME=	xfce4-settings-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/xfce4-settings/4.13/

HOMEPAGE=	http://docs.xfce.org/xfce/xfce4-settings/start
COMMENT=	Xfce settings manager

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--enable-sound-settings
CONFIGURE_ARGS+=	--enable-pluggable-dialogs

PKG_SYSCONFSUBDIR=	xdg

CONF_FILES=	${XFCE4_EGBASE}/menus/xfce-settings-manager.menu \
		${PKG_SYSCONFDIR}/menus/xfce-settings-manager.menu \
		${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml/xsettings.xml \
		${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xsettings.xml \
		${XFCE4_EGBASE}/autostart/xfsettingsd.desktop \
		${PKG_SYSCONFDIR}/autostart/xfsettingsd.desktop

MAKE_DIRS+=	${PKG_SYSCONFDIR}/menus \
		${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml \
		${XFCE4_EGBASE}/autostart \
		${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../devel/xfce4-conf/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
