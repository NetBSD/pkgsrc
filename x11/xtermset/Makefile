# $NetBSD: Makefile,v 1.11 2005/02/21 20:26:15 hubertf Exp $
#

DISTNAME=	xtermset-0.5.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clts/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bje.nu/apps/xtermset/
COMMENT=	Change things like foreground color, size etc. on an xterm

USE_BUILDLINK3=	YES
#USE_X11BASE=	YES
GNU_CONFIGURE=	yes

xpost-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.ms ${PREFIX}/share/doc/xtermset
	nroff -ms ${WRKSRC}/ctlseqs.ms >${WRKSRC}/ctlseqs.0
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.0 ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xtermset

.include "../../mk/bsd.pkg.mk"
