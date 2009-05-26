# $NetBSD: Makefile,v 1.111 2009/05/26 18:37:27 drochner Exp $
#

DISTNAME=		gnome-panel-2.26.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-panel/2.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel application

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=		${PREFIX}/share/examples/gnome-panel
CONF_FILES+=	${PREFIX}/share/examples/gnome-panel/org.gnome.ClockApplet.Mechanism.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.gnome.ClockApplet.Mechanism.conf

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libpanel-applet/libpanelapplet-2.0.pc.in

#CPPFLAGS+=	-DPANEL_GNOME_LOGO_ICON="\"netbsd-logo-icon-transparent\""

GCONF_SCHEMAS=	clock.schemas
GCONF_SCHEMAS+=	fish.schemas
GCONF_SCHEMAS+=	panel-global.schemas
GCONF_SCHEMAS+=	panel-general.schemas
GCONF_SCHEMAS+=	panel-toplevel.schemas
GCONF_SCHEMAS+=	panel-object.schemas
GCONF_SCHEMAS+=	panel-compatibility.schemas
GCONF_SCHEMAS+=	workspace-switcher.schemas
GCONF_SCHEMAS+=	window-list.schemas
GCONF_ENTRIES=		panel-default-setup.entries

BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.15.1
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.5.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.13.0

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-panel
PKG_SUPPORTED_OPTIONS=	evolution
PKG_SUGGESTED_OPTIONS=	evolution

.include "../../mk/bsd.options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.24.1
.include "../../devel/libgweather/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mevolution)
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif
.include "../../net/ORBit2/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../security/policykit-gnome/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
