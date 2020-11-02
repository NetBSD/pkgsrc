# $NetBSD: Makefile,v 1.1 2020/11/02 12:32:20 nia Exp $

DISTNAME=	libwebsockets-4.1.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=warmcat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libwebsockets.org/
COMMENT=	Lightweight C library for websocket clients and servers
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DLWS_WITH_LIBUV=ON

# Not building from a git checkout, so this is broken.
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Git=TRUE

CMAKE_ARGS+=	-DLWS_WITHOUT_TESTAPPS=ON
# Attempts to modify /etc during configure
CMAKE_ARGS+=	-DLWS_WITHOUT_TEST_SERVER=ON
CMAKE_ARGS+=	-DLWS_WITHOUT_TEST_SERVER_EXTPOLL=ON
CMAKE_ARGS+=	-DLWS_WITHOUT_TEST_PING=ON
CMAKE_ARGS+=	-DLWS_WITHOUT_TEST_CLIENT=ON

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		libwebsockets.pc
PKGCONFIG_OVERRIDE+=		libwebsockets_static.pc

.include "../../devel/libuv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
