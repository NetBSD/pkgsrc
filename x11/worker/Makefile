# $NetBSD: Makefile,v 1.1.1.1 2006/11/25 15:41:26 uebayasi Exp $
#

DISTNAME=	worker-2.14.1
CATEGORIES=	x11
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.boomerangsworld.de/cms/worker/
COMMENT=	Highly configurable two-panes file manager for X11

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

#DEPENDS+=	xview-config>=3.2.1:../../x11/xview-config
#DEPENDS+=	xview-lib>=3.2.1:../../x11/xview-lib
#DEPENDS+=	xview-clients>=3.2.1:../../x11/xview-clients

USE_X11BASE=	yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
