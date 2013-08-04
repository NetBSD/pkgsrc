# $NetBSD: Makefile,v 1.6 2013/08/04 13:11:18 kleink Exp $

DISTNAME=	Flask-Login-0.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Login/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask-login.readthedocs.org/
COMMENT=	User session management for Flask
LICENSE=	mit

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	31 32

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
