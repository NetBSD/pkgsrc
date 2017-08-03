# $NetBSD: Makefile,v 1.3 2017/08/03 07:48:52 adam Exp $

DISTNAME=	sanic-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sanic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/channelcat/sanic
COMMENT=	Microframework based on uvloop, httptools, and learnings of flask
LICENSE=	mit AND apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiofiles>=0.3.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.0.9:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-ujson>=1.35:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.5.3:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-websockets>=3.2:../../www/py-websockets

PYTHON_VERSIONS_ACCEPTED=	36 35

USE_LANGUAGES=		c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
