# $NetBSD: Makefile,v 1.19 2024/06/02 14:30:01 ryoon Exp $

DISTNAME=	slop-7.5
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=naelstrof/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/naelstrof/slop
COMMENT=	X display selection tool
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
FORCE_CXX_STD=	c++17

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
