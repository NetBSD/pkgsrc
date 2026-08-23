# $NetBSD: Makefile,v 1.6 2026/08/23 08:16:00 wiz Exp $

DISTNAME=	sphinx_argparse-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-argparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sphinx-argparse.readthedocs.io/
COMMENT=	Sphinx extension that automatically documents argparse commands and options
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=0:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-sphinx>=5.1.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.19:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
