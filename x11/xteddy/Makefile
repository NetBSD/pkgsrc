# $NetBSD: Makefile,v 1.17 2006/12/15 20:33:06 joerg Exp $

DISTNAME=	xteddy-1.1
PKGREVISION=	1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy/
COMMENT=	Cuddly teddy bear for your desktop

GNU_CONFIGURE=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
