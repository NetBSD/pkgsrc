# $NetBSD: Makefile,v 1.3 2016/09/19 09:52:21 fhajny Exp $
#

DISTNAME=	yaml-cpp-0.5.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbeder/yaml-cpp/
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

GITHUB_TAG=	${DISTNAME}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
