# $NetBSD: Makefile,v 1.2 2020/07/08 16:36:04 nia Exp $

DISTNAME=	lua-date-2.1.2
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	time lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tieske/}
GITHUB_PROJECT=	date
GITHUB_TAG=	version_${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://tieske.github.io/date/
COMMENT=	Date and Time module for Lua 5.x
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted-[0-9]*:../../devel/lua-busted

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/date.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/date.lua

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/busted${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
