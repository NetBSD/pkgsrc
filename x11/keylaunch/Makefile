# $NetBSD: Makefile,v 1.1.1.1 2001/11/25 09:40:08 zuntum Exp $
#

DISTNAME=	keylaunch-1.3.0
CATEGORIES=	x11
MASTER_SITES=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/download.htm
COMMENT=	X utility for binding commands to a hot key

WRKSRC=		${WRKDIR}/keylaunch

USE_GMAKE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/keylaunch
	${INSTALL_DATA} ${WRKSRC}/example_rc ${PREFIX}/share/examples/keylaunch/keylaunch.rc

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
