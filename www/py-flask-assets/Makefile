# $NetBSD: Makefile,v 1.4 2014/12/31 13:57:32 wiz Exp $

DISTNAME=	Flask-Assets-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Assets/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/miracle2k/flask-assets
COMMENT=	Flask webassets integration
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-webassets>=0.10:../../www/py-webassets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
