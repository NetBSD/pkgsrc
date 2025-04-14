# $NetBSD: Makefile,v 1.9 2025/04/14 18:56:06 adam Exp $

DISTNAME=	flask_static_digest-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Static-Digest/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/nickjj/flask-static-digest
COMMENT=	Flask extension for md5 tagging and gzipping static files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
