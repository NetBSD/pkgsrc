# $NetBSD: Makefile,v 1.3 2013/06/25 13:32:32 kleink Exp $

DISTNAME=	Frozen-Flask-0.11
PKGNAME=	${PYPKGPREFIX}-flask-frozen-0.11
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Frozen-Flask/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Frozen-Flask
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}
USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	31 32

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
