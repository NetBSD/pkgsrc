# $NetBSD: Makefile,v 1.13 2020/11/24 09:23:53 adam Exp $

DISTNAME=	uvicorn-0.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvicorn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.uvicorn.org/
COMMENT=	The lightning-fast ASGI server
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-h11>=0.8:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.1.1:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.14.0:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-websockets>=8.0:../../www/py-websockets

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uvicorn uvicorn-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
