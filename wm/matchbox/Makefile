# $NetBSD: Makefile,v 1.12 2004/03/10 14:12:51 xtraeme Exp $
#

DISTNAME=	matchbox-0.3.6
CATEGORIES=	wm x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/matchbox/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://handhelds.org/~mallum/matchbox/
COMMENT=	Window manager designed for computers with small displays

USE_BUILDLINK3=	YES
USE_X11=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
