# $NetBSD: Makefile,v 1.3 2002/09/23 23:23:26 jlam Exp $
#

DISTNAME=	matchbox-0.3.2
CATEGORIES=	wm
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/matchbox/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://handhelds.org/~mallum/matchbox/
COMMENT=	window manager designed for computers with small displays

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
