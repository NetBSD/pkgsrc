# $NetBSD: Makefile,v 1.5 2022/02/19 20:47:21 nia Exp $

DISTNAME=	lua-date-2.2
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	time lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tieske/}
GITHUB_PROJECT=	date
GITHUB_TAG=	version_${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://tieske.github.io/date/
COMMENT=	Date and Time module for Lua 5.x
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-cov-[0-9]*:../../devel/lua-cov

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	# none
NO_BUILD=	yes

LUA_USE_BUSTED=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/date.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/date.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
