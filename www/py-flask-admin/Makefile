# $NetBSD: Makefile,v 1.34 2026/05/10 13:01:37 wiz Exp $

DISTNAME=	flask_admin-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flask-admin/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/flask-admin/flask-admin
COMMENT=	Simple and extensible administrative interface framework for Flask
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms-[0-9]*:../../www/py-wtforms
TEST_DEPENDS+=	${PYPKGPREFIX}-arrow-[0-9]*:../../time/py-arrow
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-citext-[0-9]*:../../time/py-citext
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-sqlalchemy-[0-9]*:../../www/py-flask-sqlalchemy
TEST_DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils-[0-9]*:../../databases/py-sqlalchemy-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-mongo-[0-9]*:../../databases/py-mongo
TEST_DEPENDS+=	${PYPKGPREFIX}-peewee-[0-9]*:../../databases/py-peewee
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
