# $NetBSD: Makefile,v 1.2 2026/10/13 11:30:53 adam Exp $

DISTNAME=	jsonpatch-1.35
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpatch/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-patch
COMMENT=	Library to apply JSON Patches according to RFC 6902
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jsonpointer>=3.2:../../textproc/py-jsonpointer

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jsondiff jsonpatch

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
