# $NetBSD: Makefile,v 1.67 2024/12/27 08:20:57 wiz Exp $

DISTNAME=	hot-babe-0.2.2
PKGREVISION=	44
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
