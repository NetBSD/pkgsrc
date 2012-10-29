# $NetBSD: Makefile,v 1.18 2012/10/29 05:06:54 asau Exp $
#

DISTNAME=	unclutter-8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Remove idle cursor image from screen

WRKSRC=		${WRKDIR}/unclutter
USE_IMAKE=	yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
