# $NetBSD: Makefile,v 1.6 2019/06/14 15:17:17 adam Exp $

DISTNAME=	numpydoc-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpydoc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/numpy/numpydoc
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6.5:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
