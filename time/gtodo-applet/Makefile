# $NetBSD: Makefile,v 1.21 2007/09/21 13:04:25 wiz Exp $
#

DISTNAME=	gtodo-applet-0.1
PKGREVISION=	14
CATEGORIES=	time gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gtodo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qballcow.nl/index.php?s=4
COMMENT=	GNOME applet for the gtodo application

DEPENDS+=		gtodo>=0.14:../../time/gtodo

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		YES

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
