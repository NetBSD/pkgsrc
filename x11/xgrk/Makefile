# $NetBSD: Makefile,v 1.3 2006/07/06 21:14:20 jlam Exp $
#

DISTNAME=		xgrk-1.6.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://www.softlab.ece.ntua.gr/~sivann/xgrk/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.softlab.ece.ntua.gr/~sivann/xgrk/
COMMENT=		Greek keyboard switcher for X11

USE_TOOLS=	gmake

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/xgrk	${PREFIX}/bin
	${INSTALL_PROGRAM}	${WRKSRC}/xgrk2	${PREFIX}/bin
	${INSTALL_DATA_DIR}	${PREFIX}/share/doc/xgrk
	${INSTALL_DATA}		${WRKSRC}/README ${PREFIX}/share/doc/xgrk

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
