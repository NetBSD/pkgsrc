# $NetBSD: Makefile,v 1.78 2006/09/15 15:12:51 jmmv Exp $
#

DISTNAME=		gnome-panel-2.16.0
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-panel/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel application

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libpanel-applet/libpanelapplet-2.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

#CPPFLAGS+=	-DPANEL_GNOME_LOGO_ICON="\"netbsd-logo-icon-transparent\""

GCONF2_SCHEMAS= 	clock.schemas
GCONF2_SCHEMAS+=	fish.schemas
GCONF2_SCHEMAS+=	panel-global.schemas
GCONF2_SCHEMAS+=	panel-general.schemas
GCONF2_SCHEMAS+=	panel-toplevel.schemas
GCONF2_SCHEMAS+=	panel-object.schemas
GCONF2_SCHEMAS+=	panel-compatibility.schemas
GCONF2_SCHEMAS+=	workspace-switcher.schemas
GCONF2_SCHEMAS+=	window-list.schemas
GCONF2_ENTRIES=		panel-default-setup.entries

BUILDLINK_API_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.14.2
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.libglade2+=	libglade2>=2.5.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.13.0
BUILDLINK_API_DEPENDS.libwnck+=		libwnck>=2.13.5

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-panel
PKG_SUPPORTED_OPTIONS=	evolution
PKG_SUGGESTED_OPTIONS=	evolution
.include "../../mk/bsd.options.mk"

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mevolution)
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
