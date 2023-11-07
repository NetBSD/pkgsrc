# $NetBSD: Makefile,v 1.15 2023/11/07 22:38:08 wiz Exp $

DISTNAME=	MechanicalSoup-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MechanicalSoup/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/hickford/MechanicalSoup
COMMENT=	Library for automating interaction with websites
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.7:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=1.3.0:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.1.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin-[0-9]*:../../www/py-test-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
