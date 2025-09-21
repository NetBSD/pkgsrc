# $NetBSD: Makefile,v 1.15 2025/09/21 16:36:38 wiz Exp $

DISTNAME=	utf8-cpp-4.0.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nemtrif/}
GITHUB_PROJECT=	utfcpp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/nemtrif/utfcpp
COMMENT=	UTF-8 header library for C++
LICENSE=	boost-license

USE_LANGUAGES=	c++

CMAKE_CONFIGURE_ARGS+=	-DUTF8_SAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DUTF8_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
