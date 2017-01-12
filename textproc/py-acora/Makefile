# $NetBSD: Makefile,v 1.4 2017/01/12 00:45:31 rodent Exp $

DISTNAME=	acora-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acora/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/acora
COMMENT=	Fast multi-keyword search engine for text strings in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython>=0.20.1:../../devel/py-cython

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
