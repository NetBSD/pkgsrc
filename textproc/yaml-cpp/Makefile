# $NetBSD: Makefile,v 1.4 2016/09/23 08:39:53 roy Exp $
#

DISTNAME=	yaml-cpp-0.5.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jbeder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbeder/yaml-cpp/
COMMENT=	YAML parser and emitter for C++
LICENSE=	mit

GITHUB_TAG=	${DISTNAME}

EXTRACT_USING=		bsdtar
USE_CMAKE=		yes
USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE+=	yaml-cpp.pc.cmake

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
