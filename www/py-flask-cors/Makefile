# $NetBSD: Makefile,v 1.10 2024/10/23 09:38:50 adam Exp $

DISTNAME=	flask_cors-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-CORS/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/corydolphin/flask-cors
COMMENT=	Flask extension for handling Cross Origin Resource Sharing (CORS)
LICENSE=	modified-bsd

WHEEL_NAME=	Flask_Cors-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-flask>=0.9:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
