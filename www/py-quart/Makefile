# $NetBSD: Makefile,v 1.1 2025/12/05 21:14:29 wiz Exp $

DISTNAME=	quart-0.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/quart/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/quart/
COMMENT=	Python ASGI web framework with the same API as Flask
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-aiofiles-[0-9]*:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.6:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-click>=8.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-flask>=3.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-hypercorn>=0.11.2:../../www/py-hypercorn
DEPENDS+=	${PYPKGPREFIX}-itsdangerous-[0-9]*:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=3.0:../../www/py-werkzeug
# no tests included
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
