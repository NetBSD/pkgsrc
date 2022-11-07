# $NetBSD: Makefile,v 1.3 2022/11/07 10:19:27 adam Exp $

DISTNAME=	utf8-cpp-3.2.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nemtrif/}
GITHUB_PROJECT=	utfcpp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/nemtrif/utfcpp
COMMENT=	UTF-8 header library for C++
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c++
CMAKE_ARGS+=	-DUTF8_SAMPLES=OFF
CMAKE_ARGS+=	-DUTF8_TESTS=OFF

.include "../../mk/bsd.pkg.mk"
