# $NetBSD: Makefile,v 1.13 2025/02/23 19:30:20 wiz Exp $

DISTNAME=	sphinxcontrib_devhelp-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-devhelp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sphinx-doc.org/
COMMENT=	Sphinx API for Devhelp document
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=5:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
