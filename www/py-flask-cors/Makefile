# $NetBSD: Makefile,v 1.8 2023/09/06 07:27:56 kleink Exp $

DISTNAME=	Flask-Cors-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-CORS/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/corydolphin/flask-cors
COMMENT=	Flask extension for handling Cross Origin Resource Sharing (CORS)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>=0.9:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
