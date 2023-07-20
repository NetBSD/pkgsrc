# $NetBSD: Makefile,v 1.11 2023/07/20 09:46:34 nia Exp $

DISTNAME=	yaml-cpp-0.7.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeder/}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbeder/yaml-cpp
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DYAML_BUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DYAML_CPP_BUILD_TESTS=OFF # issue 539

USE_CXX_FEATURES+=	c++11

PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

.include "../../mk/bsd.pkg.mk"
