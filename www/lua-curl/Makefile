# $NetBSD: Makefile,v 1.43 2024/05/29 16:34:52 adam Exp $

DISTNAME=	lua-curl-0.3.13
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//}
PKGREVISION=	8
CATEGORIES=	www lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Lua-cURL/}
GITHUB_PROJECT=	Lua-cURLv3
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/Lua-cURL/Lua-cURLv3
COMMENT=	Full lua bindings for libcurl
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin" && ${OPSYS} != "Linux"
LDFLAGS+=	-shared
.endif

MAKE_FLAGS+=	LUA_CMOD=${LUA_CDIR}
MAKE_FLAGS+=	LUA_LMOD=${LUA_LDIR}
MAKE_FLAGS+=	LUA_IMPL=lua-${_LUA_DOT_VERSION}

INSTALLATION_DIRS+=	${LUA_CDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/cURL/impl

do-install:
	${INSTALL_LIB} ${WRKSRC}/lcurl.so ${DESTDIR}${PREFIX}/${LUA_CDIR}
	${INSTALL_DATA} ${WRKSRC}/src/lua/cURL.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/lua/cURL/safe.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cURL
	${INSTALL_DATA} ${WRKSRC}/src/lua/cURL/utils.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cURL
	${INSTALL_DATA} ${WRKSRC}/src/lua/cURL/impl/cURL.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cURL/impl

.include "../../www/curl/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../lang/lua/tool.mk"
.include "../../mk/bsd.pkg.mk"
