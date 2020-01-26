# $NetBSD: Makefile,v 1.4 2020/01/26 17:32:17 rillig Exp $

DISTNAME=	rapidjson-1.1.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tencent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://rapidjson.org/
COMMENT=	Fast JSON parser/generator with SAX/DOM style API
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++11

CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=TRUE

PKGCONFIG_OVERRIDE+=	RapidJSON.pc.in
BUILDLINK_TRANSFORM+=	rm:-march=native rm:-Werror

.include "../../mk/bsd.pkg.mk"
