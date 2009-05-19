# $NetBSD: Makefile,v 1.11 2009/05/19 08:59:39 wiz Exp $
#

DISTNAME=	xcruise-0.24
PKGREVISION=	1
CATEGORIES=	x11 graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcruiser/}

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://xcruiser.sourceforge.net/
COMMENT=	Navigate through a three-dimensional view of a file system
#LICENSE=	GPL

USE_IMAKE=	yes

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/doc/xcruise

post-install:
	${INSTALL_DATA} ${WRKSRC}/XCruise.ad ${PREFIX}/lib/X11/app-defaults/XCruise
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/xcruise

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
