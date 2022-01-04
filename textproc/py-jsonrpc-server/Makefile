# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:57 wiz Exp $

DISTNAME=	python-jsonrpc-server-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	textproc net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-jsonrpc-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/palantir/python-jsonrpc-server
COMMENT=	Asynchronous JSON RPC server for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # textproc/py-ujson

DEPENDS+=	${PYPKGPREFIX}-ujson>=3:../../textproc/py-ujson
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	test:test

# does not work either
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
