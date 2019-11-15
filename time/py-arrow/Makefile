# $NetBSD: Makefile,v 1.14 2019/11/15 14:09:45 adam Exp $

DISTNAME=	arrow-0.15.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arrow/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/crsmithdev/arrow
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-chai-[0-9]*:../../devel/py-chai
TEST_DEPENDS+=	${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
TEST_DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache>=1.2.1:../../devel/py-backports.functools_lru_cache
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
