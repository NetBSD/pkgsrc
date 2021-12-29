# $NetBSD: Makefile,v 1.2 2021/12/29 17:00:23 adam Exp $

DISTNAME=	utf8-cpp-3.2.1
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
