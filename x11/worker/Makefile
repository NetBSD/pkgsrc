# $NetBSD: Makefile,v 1.6 2012/10/29 05:06:56 asau Exp $
#

DISTNAME=	worker-2.14.1
PKGREVISION=	1
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
REPLACE_BASH+=	scripts/*.sh scripts/*r
USE_TOOLS+=	bash:run

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
