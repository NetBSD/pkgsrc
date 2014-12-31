# $NetBSD: Makefile,v 1.8 2014/12/31 13:57:32 wiz Exp $

DISTNAME=	Frozen-Flask-0.11
PKGNAME=	${PYPKGPREFIX}-flask-frozen-0.11
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Frozen-Flask/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Frozen-Flask
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
