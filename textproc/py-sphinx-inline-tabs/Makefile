# $NetBSD: Makefile,v 1.1 2022/02/07 15:26:43 wiz Exp $

DISTNAME=	sphinx_inline_tabs-2022.1.2b11
PKGNAME=	${PYPKGPREFIX}-sphinx-inline-tabs-2022.1.2beta11
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-inline-tabs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pradyunsg/sphinx-inline-tabs
COMMENT=	Sphinx module to add inline tabbed content
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
