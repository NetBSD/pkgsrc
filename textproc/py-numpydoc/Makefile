# $NetBSD: Makefile,v 1.7 2019/10/21 22:01:05 adam Exp $

DISTNAME=	numpydoc-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpydoc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/numpy/numpydoc
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2

PYTHON_VERSIONED_DEPENDENCIES=	sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
