# $NetBSD: Makefile,v 1.5 2023/11/07 22:38:07 wiz Exp $

DISTNAME=	sphinxcontrib_qthelp-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-qthelp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sphinx-doc.org/
COMMENT=	Sphinx API for QtHelp document
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=0:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0.0:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
