# $NetBSD: Makefile,v 1.7 2020/07/21 10:59:04 adam Exp $

DISTNAME=	deepdiff-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jsonpickle>=1.0:../../textproc/py-jsonpickle
DEPENDS+=	${PYPKGPREFIX}-mmh3-[0-9]*:../../devel/py-mmh3
DEPENDS+=	${PYPKGPREFIX}-ordered-set>=3.1:../../devel/py-ordered-set
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
