# $NetBSD: Makefile,v 1.7 2020/07/21 10:57:12 adam Exp $

DISTNAME=	jsonpickle-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpickle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jsonpickle.github.io/
COMMENT=	Python library for serializing any arbitrary object graph into JSON
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
