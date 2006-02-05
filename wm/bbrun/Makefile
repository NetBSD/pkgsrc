# $NetBSD: Makefile,v 1.16 2006/02/05 23:11:12 joerg Exp $

DISTNAME=	bbrun-1.3
PKGREVISION=	4
CATEGORIES=	wm x11
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.dwave.net/~jking/bbrun/
COMMENT=	Run utility for BlackBox

WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
USE_TOOLS+=	gmake

BUILD_TARGET=	bbrun

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bbrun
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/bbrun

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
