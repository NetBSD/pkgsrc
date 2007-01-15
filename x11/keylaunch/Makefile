# $NetBSD: Makefile,v 1.15 2007/01/15 16:58:16 joerg Exp $
#

DISTNAME=	keylaunch-1.3.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/download.htm
COMMENT=	X utility for binding commands to a hot key

WRKSRC=		${WRKDIR}/keylaunch
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/keylaunch
	${INSTALL_DATA} ${WRKSRC}/example_rc \
		${PREFIX}/share/examples/keylaunch/keylaunch.rc

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
