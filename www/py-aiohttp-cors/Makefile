# $NetBSD: Makefile,v 1.1 2019/11/03 00:59:34 markd Exp $

DISTNAME=	aiohttp-cors-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp_cors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp-cors
COMMENT=	CORS support for aiohttp
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=2.2.0:../../www/py-aiohttp

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
