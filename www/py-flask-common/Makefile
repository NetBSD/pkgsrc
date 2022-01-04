# $NetBSD: Makefile,v 1.4 2022/01/04 20:55:25 wiz Exp $

DISTNAME=	Flask-Common-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Common/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/flask-common
COMMENT=	Common functionality for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-crayons-[0-9]*:../../devel/py-crayons
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-caching-[0-9]*:../../www/py-flask-caching
DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
DEPENDS+=	${PYPKGPREFIX}-maya-[0-9]*:../../time/py-maya
DEPENDS+=	${PYPKGPREFIX}-meinheld-[0-9]*:../../www/py-meinheld
DEPENDS+=	${PYPKGPREFIX}-whitenoise-[0-9]*:../../www/py-whitenoise

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-gunicorn

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
