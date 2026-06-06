# $NetBSD: Makefile,v 1.1 2026/06/06 07:18:42 adam Exp $

DISTNAME=	sphinxnotes_mock-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxnotes-mock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sphinx.silverrainz.me/mock/
COMMENT=	Sphinx extension for masking unsupported directives and roles
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=5:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.0:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
