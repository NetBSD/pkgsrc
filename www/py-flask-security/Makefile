# $NetBSD: Makefile,v 1.22 2025/02/23 20:55:13 wiz Exp $

DISTNAME=	flask_security-5.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Security/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://flask-security.readthedocs.io/
COMMENT=	Simple security for Flask apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-email_validator>=2.0.0:../../mail/py-email_validator
DEPENDS+=	${PYPKGPREFIX}-flask>=3.0.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.6.3:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-flask-principal>=0.4.0:../../www/py-flask-principal
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=1.1.2:../../www/py-flask-wtf
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.10.0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.1.0:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.4:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-wtforms>=3.0.0:../../www/py-wtforms

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
