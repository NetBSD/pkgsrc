# $NetBSD: Makefile,v 1.9 2024/01/01 11:47:34 adam Exp $

DISTNAME=	pytest_httpx-0.28.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-httpx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://colin-b.github.io/pytest_httpx/
COMMENT=	Send responses to httpx
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.26:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.23:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
