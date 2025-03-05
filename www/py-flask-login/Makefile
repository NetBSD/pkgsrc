# $NetBSD: Makefile,v 1.25 2025/03/05 10:54:25 wiz Exp $

DISTNAME=	Flask-Login-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Login/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-login.readthedocs.org/
COMMENT=	User session management for Flask
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0.4:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=1.0.1:../../www/py-werkzeug

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
