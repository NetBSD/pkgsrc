# $NetBSD: Makefile,v 1.2 2002/09/23 22:38:06 jlam Exp $
#

DISTNAME=	keylaunch-1.3.0
CATEGORIES=	x11
MASTER_SITES=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kensden.pwp.blueyonder.co.uk/Oroborus/download.htm
COMMENT=	X utility for binding commands to a hot key

WRKSRC=		${WRKDIR}/keylaunch

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/keylaunch
	${INSTALL_DATA} ${WRKSRC}/example_rc \
		${PREFIX}/share/examples/keylaunch/keylaunch.rc

.include "../../mk/bsd.pkg.mk"
