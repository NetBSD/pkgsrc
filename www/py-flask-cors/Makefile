# $NetBSD: Makefile,v 1.4 2021/01/06 18:53:43 kleink Exp $

DISTNAME=	Flask-Cors-3.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-CORS/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/corydolphin/flask-cors
COMMENT=	Flask extension for handling Cross Origin Resource Sharing (CORS)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.9:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
