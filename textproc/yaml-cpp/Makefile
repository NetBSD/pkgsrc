# $NetBSD: Makefile,v 1.12 2023/08/23 08:05:02 adam Exp $

DISTNAME=	yaml-cpp-0.8.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeder/}
GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbeder/yaml-cpp
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DYAML_BUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DYAML_CPP_BUILD_TESTS=OFF # issue 539

USE_CXX_FEATURES+=	c++11

PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
