# $NetBSD: Makefile,v 1.11 2004/04/18 07:38:37 snj Exp $

DISTNAME=	wmfstatus-0.4
CATEGORIES=	x11
MASTER_SITES=	http://www.finik.net/files/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.finik.net/software.html
COMMENT=	General purpose 8x5 LCD screen for WindowMaker

WRKSRC=		${WRKDIR}/${DISTNAME}/wmfstatus
USE_BUILDLINK3=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfstatus ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfstatus
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README \
		${WRKDIR}/${DISTNAME}/HINTS ${PREFIX}/share/doc/wmfstatus

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
