# $NetBSD: Makefile,v 1.2 2013/01/09 19:02:44 kleink Exp $

DISTNAME=	Flask-SQLAlchemy-0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-SQLAlchemy/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://github.com/mitsuhiko/flask-sqlalchemy
COMMENT=	Adds SQLAlchemy support to your Flask application
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6:../../databases/py-sqlalchemy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
