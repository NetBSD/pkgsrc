# $NetBSD: Makefile,v 1.7 2003/06/02 01:16:14 jschauma Exp $
#

DISTNAME=	matchbox-0.3.6
CATEGORIES=	wm x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/matchbox/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://handhelds.org/~mallum/matchbox/
COMMENT=	window manager designed for computers with small displays

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
