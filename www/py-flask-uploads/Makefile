# $NetBSD: Makefile,v 1.8 2022/01/04 20:55:28 wiz Exp $

DISTNAME=	Flask-Uploads-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Uploads/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://flask-uploads.readthedocs.io/
COMMENT=	Flexible and efficient upload handling for Flask
LICENSE=	mit

USE_LANGUAGES=	#empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
