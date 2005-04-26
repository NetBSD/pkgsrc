# $NetBSD: Makefile,v 1.43 2005/04/26 20:07:45 drochner Exp $
#

DISTNAME=	control-center-2.10.1
PKGNAME=	gnome2-${DISTNAME}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/control-center/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 configuration utility

BUILD_USES_MSGFMT=	yes

USE_MSGFMT_PLURALS=	yes
GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

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

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/themus/theme-method.conf \
		${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/fontilus/font-method.conf \
		${EGDIR}

.include "../../mk/bsd.pkg.mk"
