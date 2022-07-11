# $NetBSD: Makefile,v 1.20 2022/07/11 13:32:24 adam Exp $

DISTNAME=	arrow-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arrow/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/arrow-py/arrow
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.0:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=2021.1:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.0.0:../../converters/py-simplejson
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 37
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
