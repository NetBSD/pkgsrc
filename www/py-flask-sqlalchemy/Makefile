# $NetBSD: Makefile,v 1.11 2019/05/19 08:07:54 adam Exp $

DISTNAME=	Flask-SQLAlchemy-2.4.0
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
