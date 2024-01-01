# $NetBSD: Makefile,v 1.11 2024/01/01 09:08:40 adam Exp $

DISTNAME=	utf8-cpp-4.0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nemtrif/}
GITHUB_PROJECT=	utfcpp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/nemtrif/utfcpp
COMMENT=	UTF-8 header library for C++
LICENSE=	boost-license

USE_LANGUAGES=	c++
CMAKE_ARGS+=	-DUTF8_SAMPLES=OFF
CMAKE_ARGS+=	-DUTF8_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
