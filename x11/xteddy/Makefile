# $NetBSD: Makefile,v 1.1.1.1 1999/10/15 01:01:45 hubertf Exp $

DISTNAME=	xteddy-1.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy

GNU_CONFIGURE=	yes
USE_X11=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/xteddy
	${MKDIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../mk/bsd.pkg.mk"
