# $NetBSD: Makefile,v 1.12 2026/07/13 19:24:28 adam Exp $

DISTNAME=	tree_sitter-0.26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tree-sitter/}
# distfile name conflicts with textproc/tree-sitter
DIST_SUBDIR=	py-tree-sitter

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tree-sitter/py-tree-sitter
COMMENT=	Python bindings to the Tree-sitter parsing library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
