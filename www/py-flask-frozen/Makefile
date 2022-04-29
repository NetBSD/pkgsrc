# $NetBSD: Makefile,v 1.15 2022/04/29 11:56:45 wiz Exp $

DISTNAME=	Frozen-Flask-0.15
PKGNAME=	${PYPKGPREFIX}-flask-frozen-0.15
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Frozen-Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/Frozen-Flask/
COMMENT=	Freezes a Flask application into a set of static files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
