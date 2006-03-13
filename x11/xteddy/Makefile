# $NetBSD: Makefile,v 1.15 2006/03/13 22:53:00 hubertf Exp $

DISTNAME=	xteddy-1.1
PKGREVISION=	1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy
COMMENT=	Cuddly teddy bear for your desktop

GNU_CONFIGURE=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
