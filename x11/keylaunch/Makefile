# $NetBSD: Makefile,v 1.8 2004/04/25 02:51:22 xtraeme Exp $
#

DISTNAME=	keylaunch-1.3.0
CATEGORIES=	x11
MASTER_SITES=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/download.htm
COMMENT=	X utility for binding commands to a hot key

WRKSRC=		${WRKDIR}/keylaunch
USE_BUILDLINK3=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/keylaunch
	${INSTALL_DATA} ${WRKSRC}/example_rc \
		${PREFIX}/share/examples/keylaunch/keylaunch.rc

.include "../../mk/bsd.pkg.mk"
