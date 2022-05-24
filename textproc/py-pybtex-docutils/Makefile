# $NetBSD: Makefile,v 1.6 2022/05/24 18:51:56 jaapb Exp $

DISTNAME=	pybtex-docutils-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex-docutils/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/pybtex-docutils
COMMENT=	Docutils backend for pybtex
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pybtex>=0.16:../../textproc/py-pybtex

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
