# $NetBSD: Makefile,v 1.1 2013/01/08 19:09:03 kleink Exp $

DISTNAME=	Frozen-Flask-0.9
PKGNAME=	${PYPKGPREFIX}-flask-frozen-0.9
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Frozen-Flask/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Frozen-Flask
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}
USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
