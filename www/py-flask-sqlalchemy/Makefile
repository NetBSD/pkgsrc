# $NetBSD: Makefile,v 1.10 2017/12/12 09:53:24 adam Exp $

DISTNAME=	Flask-SQLAlchemy-2.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-SQLAlchemy/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/mitsuhiko/flask-sqlalchemy
COMMENT=	Adds SQLAlchemy support to your Flask application
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.10:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.8:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
