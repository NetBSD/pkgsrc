# $NetBSD: Makefile,v 1.17 2022/04/29 11:56:46 wiz Exp $

DISTNAME=	Flask-SQLAlchemy-2.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-SQLAlchemy/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/pallets/flask-sqlalchemy
COMMENT=	Adds SQLAlchemy support to your Flask application
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=1.0.4:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2:../../databases/py-sqlalchemy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
