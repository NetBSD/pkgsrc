# $NetBSD: Makefile,v 1.16 2023/10/28 19:57:23 wiz Exp $

DISTNAME=	flask_babel-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flask_babel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitsuhiko/flask-babel
COMMENT=	Adds i18n/l10n support to Flask applications
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-babel>=2.12:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-flask>=2.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pytz>=2022.7:../../time/py-pytz

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
