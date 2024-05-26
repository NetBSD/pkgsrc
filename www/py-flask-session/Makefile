# $NetBSD: Makefile,v 1.7 2024/05/26 19:01:03 adam Exp $

DISTNAME=	flask_session-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flask-session/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fengsp/flask-session
COMMENT=	Adds server-side session support to your Flask application
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-cachelib-[0-9]*:../../devel/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-flask>=2.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-msgspec>=0.18.6:../../devel/py-msgspec

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
