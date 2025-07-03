# $NetBSD: Makefile,v 1.25 2025/07/03 19:18:11 wiz Exp $

DISTNAME=	deepdiff-8.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=0:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-orderly-set>=5.4.1:../../devel/py-orderly-set
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.0:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=2.2.0:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas>=2.2.0:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>0:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=1.2.3:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	deepdiff/diff.py

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} deep deep-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
