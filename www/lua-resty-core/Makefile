# $NetBSD: Makefile,v 1.4 2024/08/17 15:20:21 bsiegert Exp $

DISTNAME=	lua-resty-core-0.1.28
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=openresty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openresty/lua-resty-core
COMMENT=	FFI-based Lua API for nginx modules
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

MAKE_ENV+=	LUA_INCLUDE_DIR=${PREFIX}/include/luajit-2.1
MAKE_ENV+=	LUA_LIB_DIR=${PREFIX}/share/luajit-2.1

BUILDLINK_API_DEPENDS.LuaJIT2+=	LuaJIT2>=2.1
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
