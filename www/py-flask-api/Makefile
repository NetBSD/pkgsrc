# $NetBSD: Makefile,v 1.8 2025/04/14 18:56:06 adam Exp $

DISTNAME=	Flask-API-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-API/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flask-api/flask-api
COMMENT=	Browsable web APIs for Flask
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>=2.0.0:../../www/py-flask

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

post-extract:
	${RM} -r ${WRKSRC}/flask_api/__pycache__

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
