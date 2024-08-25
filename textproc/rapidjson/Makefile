# $NetBSD: Makefile,v 1.11 2024/08/25 06:19:17 wiz Exp $

DISTNAME=	rapidjson-1.1.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tencent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://rapidjson.org/
COMMENT=	Fast JSON parser/generator with SAX/DOM style API
LICENSE=	modified-bsd

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++11
#TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=		-DRAPIDJSON_BUILD_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=ON

PKGCONFIG_OVERRIDE+=	RapidJSON.pc.in
BUILDLINK_TRANSFORM+=	rm:-march=native rm:-Werror

post-install:
	rm ${DESTDIR}${PREFIX}/include/rapidjson/*.orig

.include "../../devel/cmake/build.mk"
#.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
