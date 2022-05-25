# $NetBSD: Makefile,v 1.27 2022/05/25 15:23:51 kleink Exp $

DISTNAME=	Flask-WTF-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-WTF/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/wtforms/flask-wtf
COMMENT=	Simple integration of Flask and WTForms
LICENSE=	modified-bsd

DEPENDS+=		${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=		${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms
TEST_DEPENDS+=		${PYPKGPREFIX}-flask-babel-[0-9]*:../../www/py-flask-babel
TEST_DEPENDS+=		${PYPKGPREFIX}-flask-babelex-[0-9]*:../../www/py-flask-babelex
TEST_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=		PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
