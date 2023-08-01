# $NetBSD: Makefile,v 1.12 2023/08/01 23:20:55 wiz Exp $

DISTNAME=	cftime-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cftime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Unidata/cftime
COMMENT=	Time-handling functionality
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

TEST_ENV+=	PYTHONPATH=build/lib
do-test:
	cd ${WRKSRC}/build && ${LN} -sf lib.* lib
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
