# $NetBSD: Makefile,v 1.21 2012/10/08 12:42:18 asau Exp $

DISTNAME=	bbrun-1.3
PKGREVISION=	5
CATEGORIES=	wm x11
MASTER_SITES=	http://www.dwave.net/~jking/bbrun/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.dwave.net/~jking/bbrun/
COMMENT=	Run utility for BlackBox

WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun
USE_TOOLS+=	gmake

BUILD_TARGET=	bbrun

INSTALLATION_DIRS=	bin share/doc/bbrun

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/bbrun
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DESTDIR}${PREFIX}/share/doc/bbrun

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
