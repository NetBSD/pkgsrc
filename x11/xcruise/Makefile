# $NetBSD: Makefile,v 1.5 2001/02/17 17:07:02 wiz Exp $
#

DISTNAME=	xcruise-0.24
CATEGORIES=	x11 graphics
MASTER_SITES=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/

MAINTAINER=	minoura@netbsd.org
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
