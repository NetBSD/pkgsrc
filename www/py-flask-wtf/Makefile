# $NetBSD: Makefile,v 1.24 2021/11/24 10:33:28 wiz Exp $

DISTNAME=	Flask-WTF-0.14.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-WTF/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/lepture/flask-wtf
COMMENT=	Simple integration of Flask and WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=		${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=		${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms
TEST_DEPENDS+=		${PYPKGPREFIX}-flask-babel-[0-9]*:../../www/py-flask-babel
TEST_DEPENDS+=		${PYPKGPREFIX}-flask-babelex-[0-9]*:../../www/py-flask-babelex
TEST_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

TEST_ENV+=		PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
