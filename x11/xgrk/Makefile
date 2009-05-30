# $NetBSD: Makefile,v 1.5 2009/05/30 02:00:49 zafer Exp $
#

DISTNAME=		xgrk-1.6.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://users.softlab.ece.ntua.gr/~sivann/xgrk/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.softlab.ece.ntua.gr/~sivann/xgrk/
COMMENT=		Greek keyboard switcher for X11

USE_TOOLS=	gmake

INSTALLATION_DIRS=		bin share/doc/xgrk

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/xgrk	${PREFIX}/bin
	${INSTALL_PROGRAM}	${WRKSRC}/xgrk2	${PREFIX}/bin
	${INSTALL_DATA}		${WRKSRC}/README ${PREFIX}/share/doc/xgrk

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
