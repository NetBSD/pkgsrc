# $NetBSD: Makefile,v 1.8 2025/04/14 12:39:20 adam Exp $

DISTNAME=	python-jsonrpc-server-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	3
CATEGORIES=	textproc net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-jsonrpc-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/palantir/python-jsonrpc-server
COMMENT=	Asynchronous JSON RPC server for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ujson>=3:../../textproc/py-ujson
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
