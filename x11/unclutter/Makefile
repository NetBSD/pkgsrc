# $NetBSD: Makefile,v 1.19 2018/02/28 11:48:39 leot Exp $
#

DISTNAME=	unclutter-8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Remove idle cursor image from screen
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/unclutter
USE_IMAKE=	yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
