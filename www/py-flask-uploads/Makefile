# $NetBSD: Makefile,v 1.9 2022/04/29 11:56:46 wiz Exp $

DISTNAME=	Flask-Uploads-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Uploads/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://flask-uploads.readthedocs.io/
COMMENT=	Flexible and efficient upload handling for Flask
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask

USE_LANGUAGES=	#empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
