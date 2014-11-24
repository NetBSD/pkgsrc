# $NetBSD: Makefile,v 1.1 2014/11/24 11:27:52 obache Exp $
#

DISTNAME=	yaml-cpp-0.5.1
CATEGORIES=	textproc
MASTER_SITES=	http://yaml-cpp.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yaml-cpp/
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
