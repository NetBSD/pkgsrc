# $NetBSD: Makefile,v 1.2.2.3 2002/06/30 06:24:26 jlam Exp $

DISTNAME=	bbrun-1.3
WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
CATEGORIES=	wm x11
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.dwave.net/~jking/bbrun/
COMMENT=	run utility for BlackBox

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GMAKE=	YES

ALL_TARGET=	bbrun

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bbrun
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/bbrun

.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
