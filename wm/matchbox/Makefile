# $NetBSD: Makefile,v 1.11 2004/02/14 17:21:53 jlam Exp $
#

DISTNAME=	matchbox-0.3.6
CATEGORIES=	wm x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/matchbox/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://handhelds.org/~mallum/matchbox/
COMMENT=	Window manager designed for computers with small displays

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
