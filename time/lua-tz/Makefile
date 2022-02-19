# $NetBSD: Makefile,v 1.3 2022/02/19 20:47:21 nia Exp $

DISTNAME=	lua-tz-0.4.1
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	time lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=daurnimator/}
GITHUB_PROJECT=	luatz
GITHUB_TAG=	v0.4-1

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://daurnimator.github.io/luatz/
COMMENT=	Lua library for time and date manipulation
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG:S/^v//1}
USE_LANGUAGES=	# none
NO_BUILD=	yes

LUA_USE_BUSTED=	yes
TEST_ENV+=	TZ=GMT

INSTALLATION_DIRS+=	${LUA_LDIR}/luatz

do-install:
	${INSTALL_DATA} ${WRKSRC}/luatz/* \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/luatz

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
