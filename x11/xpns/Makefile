# $NetBSD: Makefile,v 1.24 2008/11/10 17:21:39 wiz Exp $

DISTNAME=	pns_source
PKGNAME=	xpns-1.0
PKGREVISION=	2
CATEGORIES=	x11 cad
MASTER_SITES=	http://robotics.ee.uwa.edu.au/pns/ftp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co
HOMEPAGE=	http://robotics.ee.uwa.edu.au/pns/
COMMENT=	Petri-Net Simulator for Xwindows

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
MAKE_FILE=	makefile
BUILD_TARGET=	pns

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xpns
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.shell ${PREFIX}/lib/xpns/
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${PREFIX}/bin/xpns

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xpns
	${CP} ${WRKSRC}/*.net ${PREFIX}/share/doc/xpns/

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
