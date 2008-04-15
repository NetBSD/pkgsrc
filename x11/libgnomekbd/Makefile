# $NetBSD: Makefile,v 1.10 2008/04/15 17:57:15 drochner Exp $
#

DISTNAME=	libgnomekbd-2.22.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomekbd/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome keyboard configuration library

# used a library before it was created
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt
USE_DIRS+=	xdg-1.1

GCONF_SCHEMAS+=	desktop_gnome_peripherals_keyboard_xkb.schemas
PKGCONFIG_OVERRIDE+=	libgnomekbd.pc.in
PKGCONFIG_OVERRIDE+=	libgnomekbdui.pc.in

.include "../../devel/GConf/schemas.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
