# $NetBSD: Makefile,v 1.1.1.1 2004/03/10 19:22:10 jmmv Exp $
#

DISTNAME=	gtodo-applet-0.1
CATEGORIES=	time gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gtodo/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://qballcow.nl/index.php?s=4
COMMENT=	GNOME applet for the gtodo application

DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs
DEPENDS+=		gtodo>=0.14:../../time/gtodo

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
