# $NetBSD: Makefile,v 1.17 2024/01/15 09:10:14 adam Exp $

DISTNAME=	Flask-JWT-Extended-4.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-JWT-Extended/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vimalloc/flask-jwt-extended
COMMENT=	Extended JWT integration with Flask
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.3.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-flask>=2.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.14:../../www/py-werkzeug

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
