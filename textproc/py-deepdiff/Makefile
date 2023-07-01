# $NetBSD: Makefile,v 1.13 2023/07/01 08:37:42 wiz Exp $

DISTNAME=	deepdiff-6.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ordered-set>=4.0.2:../../devel/py-ordered-set
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.23.5:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} deep deep-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
