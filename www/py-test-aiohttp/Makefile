# $NetBSD: Makefile,v 1.1 2024/08/12 12:16:33 wiz Exp $

DISTNAME=	pytest-aiohttp-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-aiohttp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/pytest-aiohttp
COMMENT=	Pytest plugin for aiohttp support
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-test>=6.1.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.1:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.17.2:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
