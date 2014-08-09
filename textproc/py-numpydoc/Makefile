# $NetBSD: Makefile,v 1.1 2014/08/09 21:53:31 wiz Exp $

DISTNAME=	numpydoc-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/numpydoc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/numpydoc
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
