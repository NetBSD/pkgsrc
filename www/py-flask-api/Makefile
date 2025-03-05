# $NetBSD: Makefile,v 1.7 2025/03/05 10:45:39 wiz Exp $

DISTNAME=	Flask-API-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-API/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flask-api/flask-api
COMMENT=	Browsable web APIs for Flask
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>=2.0.0:../../www/py-flask

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

post-extract:
	${RM} -r ${WRKSRC}/flask_api/__pycache__

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
