# $NetBSD: Makefile,v 1.4 2004/04/19 15:05:00 jmmv Exp $
#

DISTNAME=	gnome-themes-extras-0.6
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-themes-extras/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Collection of metathemes for the GNOME desktop environment

DEPENDS+=		librsvg2-gtk2>=2.6.1:../../graphics/librsvg2-gtk2
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

BUILDLINK_TRANSFORM+=	S:-DG_DISABLE_DEPRECATED:
BUILDLINK_TRANSFORM+=	S:-DGTK_DISABLE_DEPRECATED:

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2-engines/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
