# $NetBSD: Makefile,v 1.5 2001/02/25 04:18:30 hubertf Exp $

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../mk/bsd.pkg.mk"
