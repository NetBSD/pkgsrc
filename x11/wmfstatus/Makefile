# $NetBSD: Makefile,v 1.10 2004/01/20 12:28:28 agc Exp $

DISTNAME=	wmfstatus-0.4
CATEGORIES=	x11
MASTER_SITES=	http://www.finik.net/files/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.finik.net/software.html
COMMENT=	General purpose 8x5 LCD screen for WindowMaker

WRKSRC=		${WRKDIR}/${DISTNAME}/wmfstatus
USE_BUILDLINK2=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfstatus ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfstatus
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README \
		${WRKDIR}/${DISTNAME}/HINTS ${PREFIX}/share/doc/wmfstatus

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
