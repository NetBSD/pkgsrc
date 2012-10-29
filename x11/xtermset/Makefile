# $NetBSD: Makefile,v 1.19 2012/10/29 05:07:23 asau Exp $
#

DISTNAME=	xtermset-0.5.2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Change things like foreground color, size etc. on an xterm

GNU_CONFIGURE=	yes

xpost-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.ms ${PREFIX}/share/doc/xtermset
	nroff -ms ${WRKSRC}/ctlseqs.ms >${WRKSRC}/ctlseqs.0
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.0 ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xtermset

.include "../../mk/bsd.pkg.mk"
