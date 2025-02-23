# $NetBSD: Makefile,v 1.25 2025/02/23 20:16:03 wiz Exp $

DISTNAME=	arrow-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arrow/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/arrow-py/arrow
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-types-python-dateutil>=2.8.10:../../time/py-types-python-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-dateparser>=1.0.0:../../time/py-dateparser
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=2021.1:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.0.0:../../converters/py-simplejson
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

# as of 1.3.0
# 24 failed, 1813 passed, 2 xpassed, 31 warnings

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
