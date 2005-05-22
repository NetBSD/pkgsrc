# $NetBSD: Makefile,v 1.13 2005/05/22 20:08:43 jlam Exp $

DISTNAME=	bbrun-1.3
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.dwave.net/~jking/bbrun/
COMMENT=	Run utility for BlackBox

WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
USE_X11=	YES
USE_TOOLS+=	gmake

BUILD_TARGET=	bbrun

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bbrun
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/bbrun

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
