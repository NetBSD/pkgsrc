# $NetBSD: Makefile,v 1.4 2001/02/17 17:07:26 wiz Exp $

DISTNAME=	xteddy-1.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy
COMMENT=	Xteddy is a cuddly teddy bear for your X Windows desktop

USE_X11=	YES
USE_XPM=	YES
GNU_CONFIGURE=	YES

pre-install:
	${MKDIR} ${PREFIX}/share/xteddy
	${MKDIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../mk/bsd.pkg.mk"
