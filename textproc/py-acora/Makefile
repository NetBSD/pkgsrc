# $NetBSD: Makefile,v 1.7 2017/12/21 14:09:13 adam Exp $

DISTNAME=	acora-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acora/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/acora
COMMENT=	Fast multi-keyword search engine for text strings in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython>=0.20.1:../../devel/py-cython

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
