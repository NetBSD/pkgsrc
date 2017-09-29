# $NetBSD: Makefile,v 1.1 2017/09/29 21:29:01 joerg Exp $

DISTNAME=	Flask-Common-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Common/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/flask-common
COMMENT=	Common functionality for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-cache-[0-9]*:../../www/py-flask-cache
DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
DEPENDS+=	${PYPKGPREFIX}-whitenoise-[0-9]*:../../www/py-whitenoise
DEPENDS+=	${PYPKGPREFIX}-crayons-[0-9]*:../../devel/py-crayons
DEPENDS+=	${PYPKGPREFIX}-maya-[0-9]*:../../time/py-maya
DEPENDS+=	${PYPKGPREFIX}-meinheld-[0-9]*:../../www/py-meinheld

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
