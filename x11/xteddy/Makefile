# $NetBSD: Makefile,v 1.2 2000/05/31 00:28:56 itohy Exp $

DISTNAME=	xteddy-1.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy

DEPENDS+=	xpm-*:../../graphics/xpm

GNU_CONFIGURE=	yes
USE_X11=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/xteddy
	${MKDIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../mk/bsd.pkg.mk"
