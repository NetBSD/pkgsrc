# $NetBSD: Makefile,v 1.11 2004/04/18 07:41:02 snj Exp $

DISTNAME=	xteddy-1.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy
COMMENT=	Xteddy is a cuddly teddy bear for your X Windows desktop

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
