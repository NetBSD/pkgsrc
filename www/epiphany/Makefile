# $NetBSD: Makefile,v 1.83 2008/04/15 18:16:16 drochner Exp $
#

DISTNAME=	epiphany-2.22.1.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/
COMMENT=	The web browser for the GNOME Desktop

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	data/epiphany-2.22.pc

.include "options.mk"

GCONF_SCHEMAS=		epiphany.schemas
GCONF_SCHEMAS+=	epiphany-fonts.schemas
GCONF_SCHEMAS+=	epiphany-lockdown.schemas
GCONF_SCHEMAS+=	epiphany-pango.schemas

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.12.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.14.0
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.14.0
BUILDLINK_API_DEPENDS.libxml2+=		libxml2>=2.6.12

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../www/seamonkey/gecko-depends.mk"
.include "../../mk/bsd.pkg.mk"
