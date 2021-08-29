# $NetBSD: Makefile,v 1.9 2021/08/29 12:37:09 adam Exp $

DISTNAME=	yaml-cpp-0.7.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeder/}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbeder/yaml-cpp
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

CMAKE_ARGS+=	-DYAML_BUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DYAML_CPP_BUILD_TESTS=OFF # issue 539

PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

.include "../../mk/bsd.pkg.mk"
