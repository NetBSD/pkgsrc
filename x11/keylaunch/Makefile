# $NetBSD: Makefile,v 1.13 2006/02/05 23:11:39 joerg Exp $
#

DISTNAME=	keylaunch-1.3.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/download.htm
COMMENT=	X utility for binding commands to a hot key

WRKSRC=		${WRKDIR}/keylaunch
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/keylaunch
	${INSTALL_DATA} ${WRKSRC}/example_rc \
		${PREFIX}/share/examples/keylaunch/keylaunch.rc

.include "../../mk/bsd.pkg.mk"
