# $NetBSD: Makefile,v 1.1.1.1 1999/01/02 13:04:45 hubertf Exp $
#

DISTNAME=	xtermset-0.1
CATEGORIES=	x11
MASTER_SITES=	http://www.cs.vu.nl/~bernsti/xtermset/src/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.cs.vu.nl/~bernsti/xtermset/

USE_X11=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.ms ${PREFIX}/share/doc/xtermset
	nroff -ms ${WRKSRC}/ctlseqs.ms >${WRKSRC}/ctlseqs.0
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.0 ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xtermset

.include "../../mk/bsd.pkg.mk"
