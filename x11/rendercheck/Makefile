# $NetBSD: Makefile,v 1.7 2024/04/23 21:25:58 wiz Exp $

DISTNAME=	rendercheck-1.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=test/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	XRender test application

USE_FEATURES=	err
USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
