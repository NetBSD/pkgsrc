# $NetBSD: Makefile,v 1.6 2003/05/17 05:58:36 salo Exp $
#

DISTNAME=	matchbox-0.3.6
CATEGORIES=	wm x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/matchbox/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://handhelds.org/~mallum/matchbox/
COMMENT=	window manager designed for computers with small displays

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
