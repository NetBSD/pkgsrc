# $NetBSD: Makefile,v 1.4 1999/08/21 04:02:44 hubertf Exp $
#

DISTNAME=	xtermset-0.4
CATEGORIES=	x11
MASTER_SITES=	http://xtermset.netpedia.net/src/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xtermset.netpedia.net/

USE_X11BASE=	YES

post-extract:
	cd ${WRKSRC} ; gunzip xtermset.1.gz

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.ms ${PREFIX}/share/doc/xtermset
	nroff -ms ${WRKSRC}/ctlseqs.ms >${WRKSRC}/ctlseqs.0
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.0 ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xtermset

.include "../../mk/bsd.pkg.mk"
