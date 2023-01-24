# $NetBSD: Makefile,v 1.7 2023/01/24 18:36:35 wiz Exp $

DISTNAME=	rapidjson-1.1.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tencent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://rapidjson.org/
COMMENT=	Fast JSON parser/generator with SAX/DOM style API
LICENSE=	modified-bsd

USE_LANGUAGES=	c++11
TEST_TARGET=	test

CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=TRUE

PKGCONFIG_OVERRIDE+=	RapidJSON.pc.in
BUILDLINK_TRANSFORM+=	rm:-march=native rm:-Werror

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
