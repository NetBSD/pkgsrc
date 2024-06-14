# $NetBSD: Makefile,v 1.3 2024/06/14 14:51:35 adam Exp $

DISTNAME=	lua-resty-core-0.1.28
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=openresty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openresty/lua-resty-core
COMMENT=	FFI-based Lua API for nginx modules
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

MAKE_ENV+=	LUA_INCLUDE_DIR=${PREFIX}/include/luajit-2.0
MAKE_ENV+=	LUA_LIB_DIR=${PREFIX}/share/luajit-2.0.5

.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
