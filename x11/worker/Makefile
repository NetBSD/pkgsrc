# $NetBSD: Makefile,v 1.7 2015/07/04 16:18:43 joerg Exp $
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

REPLACE_BASH+=	scripts/*.sh scripts/*r
USE_TOOLS+=	bash:run

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
