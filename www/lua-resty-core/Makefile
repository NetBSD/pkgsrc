# $NetBSD: Makefile,v 1.6 2024/09/23 12:39:12 wiz Exp $

DISTNAME=	lua-resty-core-0.1.29
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=openresty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openresty/lua-resty-core
COMMENT=	FFI-based Lua API for nginx modules
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:build gmake

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_FILES.bash+=	Makefile
SUBST_SED.bash+=	-e "s,/bin/bash,${BASH},"
SUBST_MESSAGE.bash=	Fixing path to bash.

MAKE_ENV+=	LUA_INCLUDE_DIR=${PREFIX}/include/luajit-2.1
MAKE_ENV+=	LUA_LIB_DIR=${PREFIX}/share/luajit-2.1

BUILDLINK_API_DEPENDS.LuaJIT2+=	LuaJIT2>=2.1
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
