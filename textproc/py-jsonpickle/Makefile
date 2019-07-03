# $NetBSD: Makefile,v 1.5 2019/07/03 20:14:59 adam Exp $

DISTNAME=	jsonpickle-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpickle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsonpickle.github.io/
COMMENT=	Python library for serializing any arbitrary object graph into JSON
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
