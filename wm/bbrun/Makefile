# $NetBSD: Makefile,v 1.2 2002/06/17 18:57:49 tron Exp $

DISTNAME=	bbrun-1.3
WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
CATEGORIES=	wm x11
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.dwave.net/~jking/bbrun/
COMMENT=	run utility for BlackBox

USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

ALL_TARGET=	bbrun

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bbrun
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/bbrun

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
