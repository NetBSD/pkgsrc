# $NetBSD: Makefile,v 1.7 2025/08/16 15:44:02 prlw1 Exp $

DISTNAME=	uchardet-0.0.8
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://www.freedesktop.org/software/uchardet/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/uchardet/
COMMENT=	Encoding detector library ported from Mozilla
LICENSE=	mpl-1.1

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	uchardet.pc.in

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src
TEST_TARGET=	test

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/${CMAKE_BUILD_DIR}/src/version.script

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
