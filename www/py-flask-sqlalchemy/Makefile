# $NetBSD: Makefile,v 1.19 2025/02/23 21:01:54 wiz Exp $

DISTNAME=	flask_sqlalchemy-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-SQLAlchemy/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/pallets/flask-sqlalchemy
COMMENT=	Adds SQLAlchemy support to your Flask application
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0.4:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
