# $NetBSD: Makefile,v 1.7 1999/01/30 23:18:58 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/29 09:38:20 obrien Exp
#

DISTNAME=	pns_source
PKGNAME=	xpns-1.0
CATEGORIES=	x11 cad
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/petri-nets/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co
HOMEPAGE=	http://www.informatik.uni-stuttgart.de/ipvr/bv/pns/pns.html

USE_X11BASE=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	pns

.include "../../mk/bsd.prefs.mk"

do-install:
	${MKDIR} ${PREFIX}/lib/xpns
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.shell ${PREFIX}/lib/xpns/
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${PREFIX}/bin/xpns

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xpns
	${CP} ${WRKSRC}/*.net ${PREFIX}/share/doc/xpns/
.endif

.include "../../mk/bsd.pkg.mk"
