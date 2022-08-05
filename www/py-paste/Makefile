# $NetBSD: Makefile,v 1.33 2022/08/05 08:08:37 adam Exp $

DISTNAME=	Paste-3.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Paste/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonpaste.readthedocs.io/
COMMENT=	Middleware for Python WSGI applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	test:test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
