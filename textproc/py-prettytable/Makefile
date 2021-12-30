# $NetBSD: Makefile,v 1.18 2021/12/30 19:52:11 fcambus Exp $

DISTNAME=	prettytable-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prettytable/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/prettytable
COMMENT=	Display tabular data in a visually appealing ASCII table format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
