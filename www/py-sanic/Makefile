# $NetBSD: Makefile,v 1.25 2022/01/13 18:23:57 adam Exp $

DISTNAME=	sanic-21.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sanic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sanic-org/sanic
COMMENT=	Microframework based on uvloop, httptools, and learnings of flask
LICENSE=	mit AND apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiofiles>=0.6.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.0.10:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-multidict>=5.0.0:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-ujson>=1.35:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.5.3:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-sanic-routing>=0.7.0:../../www/py-sanic-routing
DEPENDS+=	${PYPKGPREFIX}-websockets>=10.0:../../www/py-websockets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sanic sanic-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
