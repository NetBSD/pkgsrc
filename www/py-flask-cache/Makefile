# $NetBSD: Makefile,v 1.2 2014/01/25 10:30:28 wiz Exp $

DISTNAME=	Flask-Cache-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Cache/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://packages.python.org/Flask-Cache/
COMMENT=	Cache extension for Flask
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
