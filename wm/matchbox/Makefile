# $NetBSD: Makefile,v 1.4 2002/10/08 02:16:46 wiz Exp $
#

DISTNAME=	matchbox-0.3.5
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
