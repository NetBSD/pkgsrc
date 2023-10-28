# $NetBSD: Makefile,v 1.35 2023/10/28 19:57:25 wiz Exp $

DISTNAME=	uvicorn-0.18.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.4.0:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.15.2:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-websockets>=10.0:../../www/py-websockets

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uvicorn uvicorn-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
