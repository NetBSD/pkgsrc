# $NetBSD: Makefile,v 1.7 2017/01/17 15:13:59 kleink Exp $

DISTNAME=	Flask-Assets-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Assets/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/miracle2k/flask-assets
COMMENT=	Flask webassets integration
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-webassets>=0.11:../../www/py-webassets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
