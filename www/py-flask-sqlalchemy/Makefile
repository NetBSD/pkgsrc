# $NetBSD: Makefile,v 1.5 2014/12/31 13:57:33 wiz Exp $

DISTNAME=	Flask-SQLAlchemy-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-SQLAlchemy/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://github.com/mitsuhiko/flask-sqlalchemy
COMMENT=	Adds SQLAlchemy support to your Flask application
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.10:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6:../../databases/py-sqlalchemy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
