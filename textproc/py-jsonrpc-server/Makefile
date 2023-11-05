# $NetBSD: Makefile,v 1.6 2023/11/05 20:43:15 wiz Exp $

DISTNAME=	python-jsonrpc-server-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	textproc net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-jsonrpc-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/palantir/python-jsonrpc-server
COMMENT=	Asynchronous JSON RPC server for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-ujson>=3:../../textproc/py-ujson
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
