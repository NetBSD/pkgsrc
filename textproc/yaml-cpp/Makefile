# $NetBSD: Makefile,v 1.7 2018/03/06 10:05:49 adam Exp $

DISTNAME=	yaml-cpp-0.6.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeder/}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbeder/yaml-cpp
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=		-DYAML_CPP_BUILD_TESTS=OFF # issue 539
PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
