# $NetBSD: Makefile,v 1.3 1999/12/22 15:37:13 sakamoto Exp $
#

DISTNAME=	xcruise-0.22
CATEGORIES=	x11 graphics
MASTER_SITES=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://tanaka-www.cs.titech.ac.jp/%7Eeuske/prog/

# LICENSE=	GPL

USE_IMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xcruise

.include "../../mk/bsd.pkg.mk"
