# $NetBSD: Makefile,v 1.8 2008/04/15 17:59:15 drochner Exp $
#

DISTNAME=	gnome-control-center-2.22.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-control-center/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 configuration utility

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.6
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

CONFLICTS+=		gnome2-control-center-[0-9]* control-center-[0-9]*

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--with-gstreamer=0.10

CPPFLAGS+=		-DDBUS_API_SUBJECT_TO_CHANGE

#PKGCONFIG_OVERRIDE+=	gnome-settings-daemon/gnome-settings-daemon.pc.in
PKGCONFIG_OVERRIDE+=	libwindow-settings/gnome-window-settings-2.0.pc.in

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	vfsmoduleconfdir=${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	menudir=${PREFIX}/share/examples/${PKGBASE}

GCONF_SCHEMAS+=	control-center.schemas
GCONF_SCHEMAS+=	themus.schemas
GCONF_SCHEMAS+=	fontilus.schemas

EGDIR=			${PREFIX}/share/examples/gnome-control-center
CONF_FILES=		${EGDIR}/theme-method.conf \
			${PKG_SYSCONFDIR}/gnome-vfs-2.0/modules/theme-method.conf
CONF_FILES+=		${EGDIR}/font-method.conf \
			${PKG_SYSCONFDIR}/gnome-vfs-2.0/modules/font-method.conf
CONF_FILES+=		${EGDIR}/gnomecc.menu \
			${PKG_SYSCONFDIR}/xdg/menus/gnomecc.menu

BUILDLINK_API_DEPENDS.glib2=	glib2>=2.8.0
BUILDLINK_API_DEPENDS.gstreamer0.10=		gstreamer0.10>=0.10.1.2
BUILDLINK_API_DEPENDS.gst-plugins0.10-base=	gst-plugins0.10-base>=0.10.1.2
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.12
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-control-center
PKG_SUPPORTED_OPTIONS=	evolution
PKG_SUGGESTED_OPTIONS=	evolution
.include "../../mk/bsd.options.mk"
PLIST_VARS+=		evolution
.if !empty(PKG_OPTIONS:Mevolution)
CONFIGURE_ARGS+=	--enable-aboutme
PLIST.evolution=	yes
.endif

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mevolution)
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/themus/theme-method.conf \
		${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs-methods/fontilus/font-method.conf \
		${EGDIR}

.include "../../mk/bsd.pkg.mk"
