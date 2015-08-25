# $NetBSD: Makefile,v 1.5 2015/08/25 16:01:46 kleink Exp $

DISTNAME=	Flask-Assets-0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Assets/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/miracle2k/flask-assets
COMMENT=	Flask webassets integration
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-webassets>=0.11:../../www/py-webassets

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
