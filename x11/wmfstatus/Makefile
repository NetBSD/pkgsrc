# $NetBSD: Makefile,v 1.7 2003/03/29 12:43:10 jmmv Exp $

DISTNAME=	wmfstatus-0.4
WRKSRC=		${WRKDIR}/${DISTNAME}/wmfstatus
CATEGORIES=	x11
MASTER_SITES=	http://www.finik.net/files/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.finik.net/software.html
COMMENT=	general purpose 8x5 LCD screen for WindowMaker

USE_BUILDLINK2=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfstatus ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfstatus
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README \
		${WRKDIR}/${DISTNAME}/HINTS ${PREFIX}/share/doc/wmfstatus

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
