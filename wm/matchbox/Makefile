# $NetBSD: Makefile,v 1.10 2003/07/21 17:34:04 martti Exp $
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
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
