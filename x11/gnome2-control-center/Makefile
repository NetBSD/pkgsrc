# $NetBSD: Makefile,v 1.69 2006/09/15 15:12:40 jmmv Exp $
#

DISTNAME=	control-center-2.16.0
PKGNAME=	gnome2-${DISTNAME}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/control-center/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 configuration utility

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.6
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--enable-aboutme
CONFIGURE_ARGS+=	--with-gstreamer=0.10
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CPPFLAGS+=		-DDBUS_API_SUBJECT_TO_CHANGE

PKGCONFIG_OVERRIDE+=	gnome-settings-daemon/gnome-settings-daemon.pc
PKGCONFIG_OVERRIDE+=	libwindow-settings/gnome-window-settings-2.0.pc

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	vfsmoduleconfdir=${PREFIX}/share/examples/${PKGBASE}

GCONF2_SCHEMAS= 	apps_gnome_settings_daemon_default_editor.schemas
GCONF2_SCHEMAS+=	apps_gnome_settings_daemon_keybindings.schemas
GCONF2_SCHEMAS+=	apps_gnome_settings_daemon_screensaver.schemas
GCONF2_SCHEMAS+=	desktop_gnome_font_rendering.schemas
GCONF2_SCHEMAS+=	desktop_gnome_peripherals_keyboard_xkb.schemas
GCONF2_SCHEMAS+=	themus.schemas
GCONF2_SCHEMAS+=	fontilus.schemas

PKG_SYSCONFSUBDIR=	gnome-vfs-2.0/modules

EGDIR=			${PREFIX}/share/examples/gnome2-control-center
CONF_FILES=		${EGDIR}/theme-method.conf \
			${PKG_SYSCONFDIR}/theme-method.conf
CONF_FILES+=		${EGDIR}/font-method.conf \
			${PKG_SYSCONFDIR}/font-method.conf

BUILDLINK_API_DEPENDS.glib2=	glib2>=2.8.0
BUILDLINK_API_DEPENDS.gstreamer0.10=		gstreamer0.10>=0.10.1.2
BUILDLINK_API_DEPENDS.gst-plugins0.10-base=	gst-plugins0.10-base>=0.10.1.2
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.12
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/themus/theme-method.conf \
		${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/fontilus/font-method.conf \
		${EGDIR}

.include "../../mk/bsd.pkg.mk"
