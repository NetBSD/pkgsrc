# $NetBSD: Makefile,v 1.3 2024/09/19 06:39:47 wiz Exp $

DISTNAME=	tree-sitter-0.23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tree-sitter/}
# distfile name conflicts with textproc/tree-sitter
DIST_SUBDIR=	py-tree-sitter

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tree-sitter/py-tree-sitter
COMMENT=	Python bindings to the Tree-sitter parsing library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
