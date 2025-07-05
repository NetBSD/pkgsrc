# $NetBSD: Makefile,v 1.5 2025/07/05 11:44:16 wiz Exp $

DISTNAME=	pytest_aiohttp-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-aiohttp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/pytest-aiohttp
COMMENT=	Pytest plugin for aiohttp support
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.11.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-test>=6.1.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.17.2:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
