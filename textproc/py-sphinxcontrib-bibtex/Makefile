# $NetBSD: Makefile,v 1.20 2026/01/06 11:18:18 wiz Exp $

DISTNAME=	sphinxcontrib_bibtex-2.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-bibtex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/sphinxcontrib-bibtex
COMMENT=	Sphinx extension for BibTeX style citations
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.20:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.5:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-pybtex>=0.25:../../textproc/py-pybtex
DEPENDS+=	${PYPKGPREFIX}-pybtex-docutils>=1.0.0:../../textproc/py-pybtex-docutils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
