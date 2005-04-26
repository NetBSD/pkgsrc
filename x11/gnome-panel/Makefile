# $NetBSD: Makefile,v 1.50 2005/04/26 20:05:24 drochner Exp $
#

DISTNAME=		gnome-panel-2.10.1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-panel/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel application

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libpanel-applet/libpanelapplet-2.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

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

BUILDLINK_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.10.0
BUILDLINK_DEPENDS.libglade2+=	libglade2>=2.5.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
