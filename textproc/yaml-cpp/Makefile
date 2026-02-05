# $NetBSD: Makefile,v 1.14 2026/02/05 08:32:58 adam Exp $

DISTNAME=	yaml-cpp-0.9.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeder/}
GITHUB_TAG=	${PKGNAME_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbeder/yaml-cpp
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

CMAKE_CONFIGURE_ARGS+=	-DYAML_BUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DYAML_CPP_BUILD_TESTS=OFF # issue 539

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
