# $NetBSD: Makefile,v 1.15 2004/12/03 15:15:13 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/29 09:38:20 obrien Exp
#

DISTNAME=	pns_source
PKGNAME=	xpns-1.0
CATEGORIES=	x11 cad
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/petri-nets/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co
HOMEPAGE=	http://www.informatik.uni-stuttgart.de/ipvr/bv/pns/pns.html
COMMENT=	Petri-Net Simulator for Xwindows

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
USE_BUILDLINK3=	yes
MAKEFILE=	makefile
BUILD_TARGET=	pns

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xpns
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.shell ${PREFIX}/lib/xpns/
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${PREFIX}/bin/xpns

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xpns
	${CP} ${WRKSRC}/*.net ${PREFIX}/share/doc/xpns/

.include "../../mk/bsd.pkg.mk"
