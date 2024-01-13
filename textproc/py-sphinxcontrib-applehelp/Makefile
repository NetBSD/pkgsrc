# $NetBSD: Makefile,v 1.14 2024/01/13 06:55:48 adam Exp $

DISTNAME=	sphinxcontrib_applehelp-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-applehelp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sphinx-doc.org/
COMMENT=	Sphinx API for Apple help books
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.7:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=5:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
