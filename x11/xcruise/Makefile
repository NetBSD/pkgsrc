# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:45 joerg Exp $
#

DISTNAME=	xcruise-0.24
PKGREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/
COMMENT=	Navigate through a three-dimensional view of a file system

# LICENSE=	GPL

USE_IMAKE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/XCruise.ad ${PREFIX}/lib/X11/app-defaults/XCruise
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/xcruise

.include "../../mk/bsd.pkg.mk"
