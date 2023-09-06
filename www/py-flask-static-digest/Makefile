# $NetBSD: Makefile,v 1.5 2023/09/06 06:48:36 kleink Exp $

DISTNAME=	Flask-Static-Digest-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Static-Digest/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/nickjj/flask-static-digest
COMMENT=	Flask extension for md5 tagging and gzipping static files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
