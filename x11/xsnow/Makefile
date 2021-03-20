# $NetBSD: Makefile,v 1.34 2021/03/20 13:24:38 gdt Exp $

DISTNAME=	xsnow-3.2.2
CATEGORIES=	x11
MASTER_SITES=	https://www.ratrabbit.nl/downloads/xsnow/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.ratrabbit.nl/ratrabbit/xsnow/index.html
COMMENT=	Create a snowy and Santa-y desktop
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
