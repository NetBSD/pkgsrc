# $NetBSD: Makefile,v 1.6 2005/07/21 16:29:58 wiz Exp $
#

DISTNAME=	gtodo-applet-0.1
PKGREVISION=	2
CATEGORIES=	time gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gtodo/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://qballcow.nl/index.php?s=4
COMMENT=	GNOME applet for the gtodo application

DEPENDS+=		gtodo>=0.14:../../time/gtodo

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		YES

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
