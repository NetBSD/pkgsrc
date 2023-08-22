# $NetBSD: Makefile,v 1.8 2023/08/22 20:40:21 adam Exp $

DISTNAME=	pybtex-docutils-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex-docutils/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/pybtex-docutils
COMMENT=	Docutils backend for pybtex
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.14:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pybtex>=0.16:../../textproc/py-pybtex

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
