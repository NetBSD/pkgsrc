# $NetBSD: Makefile,v 1.50 2024/05/29 16:35:17 adam Exp $

DISTNAME=	xsnow-3.2.2
PKGREVISION=	15
CATEGORIES=	x11
MASTER_SITES=	https://www.ratrabbit.nl/downloads/xsnow/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.ratrabbit.nl/ratrabbit/xsnow/index.html
COMMENT=	Create a snowy and Santa-y desktop
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
