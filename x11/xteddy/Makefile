# $NetBSD: Makefile,v 1.9 2001/10/24 22:11:17 jlam Exp $

DISTNAME=	xteddy-1.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy
COMMENT=	Xteddy is a cuddly teddy bear for your X Windows desktop

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy
	${INSTALL_DATA_DIR} ${PREFIX}/share/xteddy/pixmaps

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
