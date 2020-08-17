# $NetBSD: Makefile,v 1.57 2020/08/17 20:20:27 leot Exp $

DISTNAME=	hot-babe-0.2.2
PKGREVISION=	34
CATEGORIES=	x11
#MASTER_SITES=	http://dindinx.net/hotbabe/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://dindinx.net/hotbabe/
COMMENT=	System load monitor
LICENSE=	artistic

USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
