# $NetBSD: Makefile,v 1.1.1.1 2002/06/12 00:36:21 wiz Exp $
#

DISTNAME=	bbrun-1.3
WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
CATEGORIES=	wm x11
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.dwave.net/~jking/bbrun/
COMMENT=	run utility for BlackBox

USE_GMAKE=		yes
USE_BUILDLINK_ONLY=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bbrun
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/bbrun

.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
