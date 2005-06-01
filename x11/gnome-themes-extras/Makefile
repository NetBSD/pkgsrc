# $NetBSD: Makefile,v 1.13 2005/06/01 18:03:28 jlam Exp $
#

DISTNAME=	gnome-themes-extras-0.8.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-themes-extras/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Collection of metathemes for the GNOME desktop environment

DEPENDS+=		librsvg2-gtk2>=2.6.1:../../graphics/librsvg2-gtk2
BUILD_USES_MSGFMT=	yes

# NetBSD's pax-as-tar truncates filenames
EXTRACT_USING=		gtar

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2-engines/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
