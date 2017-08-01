# $NetBSD: Makefile,v 1.12 2017/08/01 18:30:02 kleink Exp $

DISTNAME=	Frozen-Flask-0.15
PKGNAME=	${PYPKGPREFIX}-flask-frozen-0.15
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Frozen-Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/Frozen-Flask/
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
