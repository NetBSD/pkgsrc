# $NetBSD: Makefile,v 1.3 2007/09/03 16:28:37 drochner Exp $
#

DISTNAME=	cairo-clock_0.3.3-1
PKGNAME=	cairo-clock-0.3.3
CATEGORIES=	time
MASTER_SITES=	http://macslow.thepimp.net/projects/cairo-clock/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://macslow.thepimp.net/?page_id=23
COMMENT=	Analog clock drawn with vector-graphics

WRKSRC=		${WRKDIR}/cairo-clock-0.3.3
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
