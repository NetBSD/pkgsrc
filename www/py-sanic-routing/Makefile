# $NetBSD: Makefile,v 1.1 2021/07/28 12:11:13 adam Exp $

DISTNAME=	sanic-routing-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sanic-routing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sanic-org/sanic-routing/
COMMENT=	Core routing component for Sanic
LICENSE=	mit

#DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# tests are not included
do-test:
	${DO_NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
