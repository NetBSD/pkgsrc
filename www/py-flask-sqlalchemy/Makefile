# $NetBSD: Makefile,v 1.18 2024/03/06 21:17:22 wiz Exp $

DISTNAME=	flask_sqlalchemy-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-SQLAlchemy/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/pallets/flask-sqlalchemy
COMMENT=	Adds SQLAlchemy support to your Flask application
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=0:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0.4:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
