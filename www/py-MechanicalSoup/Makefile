# $NetBSD: Makefile,v 1.21 2025/07/01 05:27:10 adam Exp $

DISTNAME=	mechanicalsoup-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/mechanicalsoup/MechanicalSoup/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MechanicalSoup/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/hickford/MechanicalSoup
COMMENT=	Library for automating interaction with websites
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.7:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-certifi>=2022.12.7:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.2.2:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=1.3.0:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.1.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin-[0-9]*:../../www/py-test-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

USE_LANGUAGES=	# none

# as of 1.3.0
# 69 failed, 66 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
