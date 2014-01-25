# $NetBSD: Makefile,v 1.10 2014/01/25 10:30:28 wiz Exp $

DISTNAME=	Flask-Login-0.2.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Login/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-login.readthedocs.org/
COMMENT=	User session management for Flask
LICENSE=	mit

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
