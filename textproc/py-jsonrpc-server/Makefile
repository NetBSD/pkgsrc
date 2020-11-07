# $NetBSD: Makefile,v 1.2 2020/11/07 18:56:56 wiz Exp $

DISTNAME=	python-jsonrpc-server-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-jsonrpc-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/palantir/python-jsonrpc-server
COMMENT=	Asynchronous JSON RPC server for Python
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif
DEPENDS+=	${PYPKGPREFIX}-ujson>=3:../../textproc/py-ujson

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	test:test

# does not work either
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
