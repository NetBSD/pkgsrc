# $NetBSD: Makefile,v 1.10 2002/08/25 21:52:57 jlam Exp $

DISTNAME=	xteddy-1.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy
COMMENT=	Xteddy is a cuddly teddy bear for your X Windows desktop

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
