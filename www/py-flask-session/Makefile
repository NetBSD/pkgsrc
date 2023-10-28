# $NetBSD: Makefile,v 1.5 2023/10/28 19:57:23 wiz Exp $

DISTNAME=	Flask-Session-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flask-session/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fengsp/flask-session
COMMENT=	Adds server-side session support to your Flask application
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-cachelib-[0-9]*:../../devel/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-flask>=2.2:../../www/py-flask

WHEEL_NAME=	${DISTNAME:C/-([^0-9])/_\1/g:tl}
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
