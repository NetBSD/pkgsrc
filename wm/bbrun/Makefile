# $NetBSD: Makefile,v 1.11 2004/12/03 15:15:11 wiz Exp $

DISTNAME=	bbrun-1.3
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.dwave.net/~jking/bbrun/
COMMENT=	Run utility for BlackBox

WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
USE_BUILDLINK3=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make

BUILD_TARGET=	bbrun

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bbrun
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/bbrun

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
