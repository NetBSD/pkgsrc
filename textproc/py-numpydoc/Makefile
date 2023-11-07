# $NetBSD: Makefile,v 1.11 2023/11/07 22:38:05 wiz Exp $

DISTNAME=	numpydoc-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpydoc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/numpy/numpydoc
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
