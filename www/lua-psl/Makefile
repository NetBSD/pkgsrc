# $NetBSD: Makefile,v 1.2 2020/11/05 09:09:21 ryoon Exp $

DISTNAME=	lua-psl-0.3
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//1}
PKGREVISION=	1
CATEGORIES=	www lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=daurnimator/}
GITHUB_PROJECT=	lua-psl
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://daurnimator.github.io/lua-psl/
COMMENT=	Lua bindings to libpsl, a library that handles the Public Suffix List
LICENSE=	mit

BUILD_DIRS+=	psl

INSTALLATION_DIRS+=	${LUA_CDIR}

pre-build:
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/psl/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/psl/psl.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../www/libpsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
