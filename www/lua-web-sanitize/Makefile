# $NetBSD: Makefile,v 1.2 2021/12/09 15:16:11 nia Exp $

DISTNAME=	web_sanitize-1.1.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=leafo/}
GITHUB_PROJECT=	web_sanitize
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/leafo/web_sanitize
COMMENT=	Lua library for sanitizing untrusted HTML
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

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

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/busted${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
