# $NetBSD: Makefile,v 1.3 2002/12/26 01:48:32 wiz Exp $
#

DISTNAME=	openbox-2.2.3
CATEGORIES=	wm
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox

DEPENDS+=	bsetroot>=0.1:../../wm/bsetroot

USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
