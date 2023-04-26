# $NetBSD: Makefile,v 1.32 2023/04/26 13:46:13 adam Exp $

DISTNAME=	yarl-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yarl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/yarl
COMMENT=	Yet another URL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-idna>=2.0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.0:../../databases/py-multidict
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.3.1:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
