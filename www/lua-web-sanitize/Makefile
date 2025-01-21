# $NetBSD: Makefile,v 1.5 2025/01/21 11:00:18 nia Exp $

DISTNAME=	web_sanitize-1.4.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=leafo/}
GITHUB_PROJECT=	web_sanitize
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leafo/web_sanitize
COMMENT=	Lua library for sanitizing untrusted HTML
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

LUA_USE_BUSTED=	yes

TEST_DEPENDS+=		${LUA_PKGPREFIX}-moonscript-[0-9]*:../../lang/lua-moonscript
TEST_DEPENDS+=		${LUA_PKGPREFIX}-cjson-[0-9]*:../../textproc/lua-cjson

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/web_sanitize
INSTALLATION_DIRS+=	${LUA_LDIR}/web_sanitize/query

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/web_sanitize/*.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}/web_sanitize
	${INSTALL_DATA} ${WRKSRC}/web_sanitize/query/*.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}/web_sanitize/query

pre-test:
	${PREFIX}/bin/moonc${_LUA_DOT_VERSION} ${WRKSRC}/spec/*.moon

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
