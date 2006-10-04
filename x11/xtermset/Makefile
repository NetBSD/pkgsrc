# $NetBSD: Makefile,v 1.16 2006/10/04 22:06:57 wiz Exp $
#

DISTNAME=	xtermset-0.5.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Change things like foreground color, size etc. on an xterm

#USE_X11BASE=	YES
GNU_CONFIGURE=	yes

.include "../../mk/x11.buildlink3.mk"

xpost-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.ms ${PREFIX}/share/doc/xtermset
	nroff -ms ${WRKSRC}/ctlseqs.ms >${WRKSRC}/ctlseqs.0
	${INSTALL_DATA} ${WRKSRC}/ctlseqs.0 ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/xtermset
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xtermset

.include "../../mk/bsd.pkg.mk"
