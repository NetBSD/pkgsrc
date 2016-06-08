# $NetBSD: Makefile,v 1.10 2016/06/08 17:43:45 wiz Exp $

DISTNAME=	Frozen-Flask-0.12
PKGNAME=	${PYPKGPREFIX}-flask-frozen-0.12
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
