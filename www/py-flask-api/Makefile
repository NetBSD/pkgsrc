# $NetBSD: Makefile,v 1.5 2024/01/20 10:14:48 adam Exp $

DISTNAME=	Flask-API-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-API/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flask-api/flask-api
COMMENT=	Browsable web APIs for Flask
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-flask>=2.0.0:../../www/py-flask

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${RM} -r ${WRKSRC}/flask_api/__pycache__

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
