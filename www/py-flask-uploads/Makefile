# $NetBSD: Makefile,v 1.2 2014/12/31 13:57:33 wiz Exp $

DISTNAME=	Flask-Uploads-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Uploads/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://bitbucket.org/leafstorm/flask-uploads/
COMMENT=	Flexible and efficient upload handling for Flask
LICENSE=	mit

USE_LANGUAGES=	#empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.5:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
