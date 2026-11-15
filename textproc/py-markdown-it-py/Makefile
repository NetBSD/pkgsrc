# $NetBSD: Makefile,v 1.11 2026/11/15 21:58:53 wiz Exp $

DISTNAME=	markdown_it_py-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/markdown-it-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/markdown-it-py
COMMENT=	Python port of markdown-it
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-mdurl>=0.1:../../www/py-mdurl
DEPENDS+=	${PYPKGPREFIX}-linkify-it-py>=0:../../textproc/py-linkify-it-py

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	markdown-it

# as of 4.3.0
# 1183 passed, 1 warning, 7 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
