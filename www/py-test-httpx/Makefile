# $NetBSD: Makefile,v 1.17 2024/11/28 19:52:45 adam Exp $

DISTNAME=	pytest_httpx-0.35.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-httpx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://colin-b.github.io/pytest_httpx/
COMMENT=	Send responses to httpx
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.28:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-test>=8.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.24:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
