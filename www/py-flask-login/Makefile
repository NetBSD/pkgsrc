# $NetBSD: Makefile,v 1.1 2013/01/07 20:15:01 kleink Exp $

DISTNAME=	Flask-Login-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Login/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://bitbucket.org/leafstorm/flask-login/
COMMENT=	User session management for Flask
LICENSE=	mit

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
