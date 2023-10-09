# $NetBSD: Makefile,v 1.23 2023/10/09 12:25:59 adam Exp $

DISTNAME=	arrow-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arrow/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/arrow-py/arrow
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-types-python-dateutil>=2.8.10:../../time/py-types-python-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-dateparser>=1.0.0:../../time/py-dateparser
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=2021.1:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.0.0:../../converters/py-simplejson
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
