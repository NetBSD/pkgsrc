# $NetBSD: Makefile,v 1.18 2003/12/28 14:26:18 jmmv Exp $
#

DISTNAME=		gnome-panel-2.4.1
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-panel/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel application

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
DEPENDS+=		gnome-icon-theme>=1.0.9:../../graphics/gnome-icon-theme

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libpanel-applet/libpanelapplet-2.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS= 	clock.schemas
GCONF2_SCHEMAS+=	fish.schemas
GCONF2_SCHEMAS+=	gnome-panel-screenshot.schemas
GCONF2_SCHEMAS+=	panel-global.schemas
GCONF2_SCHEMAS+=	panel-general.schemas
GCONF2_SCHEMAS+=	panel-toplevel.schemas
GCONF2_SCHEMAS+=	panel-object.schemas
GCONF2_SCHEMAS+=	panel-compatibility.schemas
GCONF2_SCHEMAS+=	workspace-switcher.schemas
GCONF2_SCHEMAS+=	window-list.schemas
GCONF2_ENTRIES=		panel-default-setup.entries

BUILDLINK_DEPENDS.GConf2=	GConf2>=2.4.0.1nb1

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libwnck/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../x11/gnome2-control-center/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
