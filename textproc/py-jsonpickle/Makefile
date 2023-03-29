# $NetBSD: Makefile,v 1.14 2023/03/29 09:34:13 wiz Exp $

DISTNAME=	jsonpickle-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpickle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jsonpickle.github.io/
COMMENT=	Python library for serializing any arbitrary object graph into JSON
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
PYTHON_VERSIONED_DEPENDENCIES+=	importlib-metadata
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools_scm:build test:test test-cov:test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
