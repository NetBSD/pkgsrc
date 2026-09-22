# $NetBSD: Makefile,v 1.1 2026/09/22 17:33:35 ryoon Exp $

DISTNAME=	jsonpatch-1.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpatch/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stefankoegl/python-json-patch
COMMENT=	Library to apply JSON Patches according to RFC 6902
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jsonpointer>=1.9:../../textproc/py-jsonpointer

USE_LANGUAGES=	# none

post-install:
.for bin in jsondiff jsonpatch
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
