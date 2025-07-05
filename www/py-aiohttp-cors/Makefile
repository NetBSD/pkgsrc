# $NetBSD: Makefile,v 1.3 2025/07/05 11:44:14 wiz Exp $

DISTNAME=	aiohttp-cors-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp_cors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp-cors
COMMENT=	CORS support for aiohttp
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=2.2.0:../../www/py-aiohttp

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
