# $NetBSD: Makefile,v 1.51 2009/03/15 19:16:58 jmcneill Exp $
#

DISTNAME=	epiphany-extensions-2.26.0
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany-extensions/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/extensions.html
COMMENT=	Extensions for the Epiphany web browser

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_DIRS+=		gnome2-1.5

# Avoid -Werror, which breaks the build sometimes.
CONFIGURE_ARGS+=	--enable-compile-warnings=no
CONFIGURE_ARGS+=	--with-extensions=all

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.5
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.epiphany+=	epiphany>=2.26.0
.include "../../www/epiphany/buildlink3.mk"
.include "../../www/seamonkey/gecko-depends.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.11.6
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
