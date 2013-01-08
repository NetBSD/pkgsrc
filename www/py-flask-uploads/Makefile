# $NetBSD: Makefile,v 1.1 2013/01/08 18:06:29 kleink Exp $

DISTNAME=	Flask-Uploads-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Uploads/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://bitbucket.org/leafstorm/flask-uploads/
COMMENT=	Flexible and efficient upload handling for Flask
LICENSE=	mit

USE_LANGUAGES=	#empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask>=0.5:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
