# $NetBSD: Makefile,v 1.5 2002/04/30 13:19:03 jschauma Exp $

DISTNAME=	wmfstatus-0.4
CATEGORIES=	x11
MASTER_SITES=	http://www.finik.net/files/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.finik.net/software.html
COMMENT=	general purpose 8x5 LCD screen for WindowMaker

USE_X11=	YES
USE_XPM=	YES

CPPFLAGS=	-I${X11BASE}/include

WRKSRC=		${WRKDIR}/${DISTNAME}/wmfstatus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfstatus ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfstatus
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README \
		${WRKDIR}/${DISTNAME}/HINTS ${PREFIX}/share/doc/wmfstatus

.include "../../mk/bsd.pkg.mk"
