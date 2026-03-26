# $NetBSD: Makefile,v 1.59 2026/03/26 12:59:05 adam Exp $

DISTNAME=	uvicorn-0.42.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvicorn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.uvicorn.org/
COMMENT=	The lightning-fast ASGI server
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-h11>=0.8:../../www/py-h11
# standard
DEPENDS+=	${PYPKGPREFIX}-dotenv>=0.13:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.6.3:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.15.2:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-watchfiles>=0.20:../../misc/py-watchfiles
DEPENDS+=	${PYPKGPREFIX}-websockets>=10.4:../../www/py-websockets
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.2:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uvicorn uvicorn-${PYVERSSUFFIX} || ${TRUE}

# Needs a2wsgi
pre-test:
	${RM} -f ${WRKSRC}/tests/middleware/test_wsgi.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
