# $NetBSD: Makefile,v 1.1 2022/03/06 08:58:21 nia Exp $

DISTNAME=	chronos-0.2.4
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	time lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=ldrumm/}
GITHUB_PROJECT=	chronos
GITHUB_TAG=	v0.2-4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ldrumm/chronos
COMMENT=	High resolution monotonic timers for Lua
LICENSE=	mit

INSTALLATION_DIRS+=	${LUA_CDIR}

BUILD_DIRS+=		src

pre-build:
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/chronos.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/chronos.so

do-test:
	LUA_CPATH=${WRKSRC}/src/?.so \
	    ${LUA_INTERPRETER} ${FILESDIR}/test.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
