# $NetBSD: Makefile,v 1.18 2024/08/10 09:42:15 wiz Exp $

DISTNAME=	Flask-Security-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Security/}

MAINTAINER=	kleink@NetBSD.org
#HOMEPAGE=	https://pythonhosted.org/Flask-Security/
COMMENT=	Simple security for Flask apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-flask>=0.11:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-babelex>=0.9.3:../../www/py-flask-babelex
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.3.0:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-flask-mail>=0.7.3:../../www/py-flask-mail
DEPENDS+=	${PYPKGPREFIX}-flask-principal>=0.3.3:../../www/py-flask-principal
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=0.13.1:../../www/py-flask-wtf
DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=0.21:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7:../../security/py-passlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
