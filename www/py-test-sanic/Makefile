# $NetBSD: Makefile,v 1.1 2023/03/03 08:26:54 adam Exp $

DISTNAME=	pytest-sanic-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-sanic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yunstanford/pytest-sanic
COMMENT=	Pytest plugin for Sanic
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-async_generator>=1.10:../../devel/py-async_generator
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.18.1:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-test>=5.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-websockets>=9.1:../../www/py-websockets

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
