# $NetBSD: Makefile,v 1.26 2025/04/14 18:56:06 adam Exp $

DISTNAME=	Flask-Login-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Login/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-login.readthedocs.org/
COMMENT=	User session management for Flask
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0.4:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=1.0.1:../../www/py-werkzeug

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
