# $NetBSD: Makefile,v 1.4 2024/02/12 05:25:03 markd Exp $

DISTNAME=	Flask-Security-Too-5.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Security-Too/}

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	https://github.com/Flask-Middleware/flask-security
COMMENT=	Simple security for Flask apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-babel>=2.12.1:../../devel/py-babel
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-email_validator>=2.0.0:../../mail/py-email_validator
DEPENDS+=	${PYPKGPREFIX}-flask>=2.3.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.6.2:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-flask-principal>=0.4.0:../../www/py-flask-principal
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=1.1.2:../../www/py-flask-wtf
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.10.0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.4:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-wtforms>=3.0.0:../../www/py-wtforms

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
