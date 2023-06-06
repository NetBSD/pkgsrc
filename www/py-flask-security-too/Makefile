# $NetBSD: Makefile,v 1.2 2023/06/06 12:42:50 riastradh Exp $

DISTNAME=	Flask-Security-Too-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Security-Too/}

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	https://github.com/Flask-Middleware/flask-security
COMMENT=	Simple security for Flask apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-babel>=2.12.1:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-email_validator>=1.1.1:../../mail/py-email_validator
DEPENDS+=	${PYPKGPREFIX}-flask>=2.3.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-principal>=0.4.0:../../www/py-flask-principal
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=1.1.1:../../www/py-flask-wtf
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.10.0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.4:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-wtforms>=3.0.0:../../www/py-wtforms

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
