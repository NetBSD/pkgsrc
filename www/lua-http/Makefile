# $NetBSD: Makefile,v 1.1 2020/07/08 14:58:49 nia Exp $

DISTNAME=	lua-http-0.3
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//1}
CATEGORIES=	www lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=daurnimator/}
GITHUB_PROJECT=	lua-http
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://daurnimator.github.io/lua-http/
COMMENT=	HTTP/1.0/1.1/2.0 client and server library for Lua
LICENSE=	mit

# XXX: update this when cqueues and ossl support Lua 5.4.
LUA_VERSIONS_ACCEPTED=	53 52 51

.include "../../lang/lua/luaversion.mk"

.if ${_LUA_DOT_VERSION} < 5.2
DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../devel/lua-BitOp
.endif

.if ${_LUA_DOT_VERSION} < 5.3
DEPENDS+=	${LUA_PKGPREFIX}-compat53-[0-9]*:../../devel/lua-compat53
.endif

DEPENDS+=	${LUA_PKGPREFIX}-basexx-[0-9]*:../../devel/lua-basexx
DEPENDS+=	${LUA_PKGPREFIX}-binaryheap-[0-9]*:../../devel/lua-binaryheap
DEPENDS+=	${LUA_PKGPREFIX}-cqueues-[0-9]*:../../devel/lua-cqueues
DEPENDS+=	${LUA_PKGPREFIX}-fifo-[0-9]*:../../devel/lua-fifo
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-patterns-[0-9]*:../../devel/lua-lpeg-patterns
DEPENDS+=	${LUA_PKGPREFIX}-ossl-[0-9]*:../../security/lua-ossl

# These are optional, but are needed for full library functionality
DEPENDS+=	${LUA_PKGPREFIX}-psl-[0-9]*:../../www/lua-psl
DEPENDS+=	${LUA_PKGPREFIX}-zlib-[0-9]*:../../archivers/lua-zlib

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}/http

do-install:
	${INSTALL_DATA} ${WRKSRC}/http/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/http

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
