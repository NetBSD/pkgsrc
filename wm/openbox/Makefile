# $NetBSD: Makefile,v 1.4 2003/01/05 20:10:12 jschauma Exp $
#

DISTNAME=	openbox-2.2.3
CATEGORIES=	wm
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Window manager based on Blackbox

DEPENDS+=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
