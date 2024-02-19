# $NetBSD: Makefile,v 1.23 2024/02/19 11:23:20 adam Exp $

DISTNAME=	tempora-5.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tempora/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/tempora
COMMENT=	Objects and routines pertaining to date and time
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=1.20:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs-[0-9]*:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer-[0-9]*:../../devel/py-test-freezer

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} calc-prorate calc-prorate-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
