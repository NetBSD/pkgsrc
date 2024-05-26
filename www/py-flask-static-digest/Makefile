# $NetBSD: Makefile,v 1.6 2024/05/26 19:04:05 adam Exp $

DISTNAME=	flask_static_digest-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Static-Digest/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/nickjj/flask-static-digest
COMMENT=	Flask extension for md5 tagging and gzipping static files
LICENSE=	mit

WHEEL_NAME=	Flask_Static_Digest-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
