# $NetBSD: Makefile,v 1.19 2025/02/04 13:14:31 adam Exp $

DISTNAME=	flask_jwt_extended-4.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-JWT-Extended/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vimalloc/flask-jwt-extended
COMMENT=	Extended JWT integration with Flask
LICENSE=	mit

WHEEL_NAME=	Flask_JWT_Extended-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.3.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-flask>=2.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.14:../../www/py-werkzeug

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
