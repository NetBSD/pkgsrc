# $NetBSD: Makefile,v 1.5 2013/08/04 13:11:18 kleink Exp $

DISTNAME=	Frozen-Flask-0.11
PKGNAME=	${PYPKGPREFIX}-flask-frozen-0.11
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Frozen-Flask/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Frozen-Flask
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	31 32

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
