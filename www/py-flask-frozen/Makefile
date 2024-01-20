# $NetBSD: Makefile,v 1.17 2024/01/20 10:21:27 adam Exp $

DISTNAME=	frozen_flask-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Frozen-Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/Frozen-Flask/
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-flask>=2.0.0:../../www/py-flask

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
