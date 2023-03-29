# $NetBSD: Makefile,v 1.1 2023/03/29 08:29:57 adam Exp $

DISTNAME=	lua-resty-lrucache-0.13
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=openresty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openresty/lua-resty-lrucache
COMMENT=	Lua-land LRU cache based on the LuaJIT FFI
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

MAKE_ENV+=	LUA_INCLUDE_DIR=${PREFIX}/include/luajit-2.0
MAKE_ENV+=	LUA_LIB_DIR=${PREFIX}/share/luajit-2.0.5
#MAKE_ENV+=	LUA_INCLUDE_DIR=${PREFIX}/include/luajit-2.1
#MAKE_ENV+=	LUA_LIB_DIR=${PREFIX}/share/luajit-2.1.0-beta3

#.include "../../lang/openresty-luajit2/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
