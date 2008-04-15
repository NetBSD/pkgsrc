# $NetBSD: Makefile,v 1.46 2008/04/15 18:17:32 drochner Exp $
#

DISTNAME=	epiphany-extensions-2.22.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany-extensions/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/extensions.html
COMMENT=	Extensions for the Epiphany web browser

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_DIRS+=		gnome2-1.5

# Avoid -Werror, which breaks the build sometimes.
CONFIGURE_ARGS+=	--enable-compile-warnings=no
CONFIGURE_ARGS+=	--with-extensions=all

GCONF_SCHEMAS=		smart-bookmarks.schemas

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/epiphany/buildlink3.mk"
.include "../../www/seamonkey/gecko-depends.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
