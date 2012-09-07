# $NetBSD: Makefile,v 1.146 2012/09/07 19:17:44 adam Exp $
#

DISTNAME=		gnome-panel-2.32.1
PKGREVISION=		16
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-panel/2.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel application

PKG_DESTDIR_SUPPORT=	user-destdir

# depends on policykit
#EGDIR=		${PREFIX}/share/examples/gnome-panel
#CONF_FILES+=	${PREFIX}/share/examples/gnome-panel/org.gnome.ClockApplet.Mechanism.conf \
#		${PKG_SYSCONFDIR}/dbus-1/system.d/org.gnome.ClockApplet.Mechanism.conf

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	bonobo/libpanel-applet/libpanelapplet-2.0.pc.in
PKGCONFIG_OVERRIDE+=	libpanel-applet/libpanelapplet-3.0.pc.in
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

# XXX this pkg installs a gio module to ${PREFIX}/lib/gnome-panel/modules
# but there are two problems with this:
# - this is not the standard module location, glib2/modules.mk
#   does not deal with this yet
# - even if called with the correct path, the resulting "giomodule.cache"
#   is empty, due to missing symbols in dynamic loading, see
#   https://bugzilla.gnome.org/show_bug.cgi?id=636255
# XXX so for now, just disable "giomodule.cache" creation to fix the
# PLIST problem reported in PR pkg/44181, until the issue is fixed
TOOLS_NOOP+=	gio-querymodules

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
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.13.0

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-panel
PKG_SUPPORTED_OPTIONS=	evolution
PKG_SUGGESTED_OPTIONS=	evolution

.include "../../mk/bsd.options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
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
# pkgsrc policykit is too old
#.include "../../security/policykit/buildlink3.mk"
#.include "../../security/policykit-gnome/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-menus+= gnome-menus>=2.28.0
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
