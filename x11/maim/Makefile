# $NetBSD: Makefile,v 1.17 2023/11/08 13:21:33 wiz Exp $

DISTNAME=	maim-5.7.4
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=naelstrof/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/naelstrof/maim
COMMENT=	Screenshot utility with improvements over scrot
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
BUILDLINK_API_DEPENDS.slop?=    slop>=7.5
.include "../../x11/slop/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
