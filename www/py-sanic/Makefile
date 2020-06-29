# $NetBSD: Makefile,v 1.14 2020/06/29 14:29:20 adam Exp $

DISTNAME=	sanic-20.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sanic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/channelcat/sanic
COMMENT=	Microframework based on uvloop, httptools, and learnings of flask
LICENSE=	mit AND apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiofiles>=0.3.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.0.10:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.9.3:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.0:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-ujson>=1.35:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.5.3:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-websockets>=7.0:../../www/py-websockets
TEST_DEPENDS+=	${PYPKGPREFIX}-uvicorn-[0-9]*:../../www/py-uvicorn

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sanic sanic-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
