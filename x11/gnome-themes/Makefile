# $NetBSD: Makefile,v 1.6 2004/01/03 18:49:56 reed Exp $
#

DISTNAME=		gnome-themes-2.4.1
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-themes/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Collection of themes and icons for GNOME 2

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../wm/metacity/buildlink2.mk"
.include "../../x11/gtk2-engines/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
