# $NetBSD: Makefile,v 1.9 2024/10/18 18:41:09 nros Exp $

DISTNAME=	libwebsockets-4.3.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=warmcat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libwebsockets.org/
COMMENT=	Lightweight C library for websocket clients and servers
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DLWS_WITH_LIBUV=ON

# Not building from a git checkout, so this is broken.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Git=TRUE

CMAKE_CONFIGURE_ARGS+=	-DLWS_WITHOUT_TESTAPPS=ON
# Attempts to modify /etc during configure
CMAKE_CONFIGURE_ARGS+=	-DLWS_WITHOUT_TEST_SERVER=ON
CMAKE_CONFIGURE_ARGS+=	-DLWS_WITHOUT_TEST_SERVER_EXTPOLL=ON
CMAKE_CONFIGURE_ARGS+=	-DLWS_WITHOUT_TEST_PING=ON
CMAKE_CONFIGURE_ARGS+=	-DLWS_WITHOUT_TEST_CLIENT=ON
# installs files into home directory
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		libwebsockets.pc
PKGCONFIG_OVERRIDE+=		libwebsockets_static.pc

.include "../../devel/cmake/build.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
