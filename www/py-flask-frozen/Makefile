# $NetBSD: Makefile,v 1.16 2023/07/21 04:36:41 adam Exp $

DISTNAME=	Frozen-Flask-0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Frozen-Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/Frozen-Flask/
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.0:../../www/py-flask

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
