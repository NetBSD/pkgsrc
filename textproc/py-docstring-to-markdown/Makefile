# $NetBSD: Makefile,v 1.7 2025/05/04 14:56:47 wiz Exp $

DISTNAME=	docstring_to_markdown-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/docstring-to-markdown/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-lsp/docstring-to-markdown
COMMENT=	On-the-fly conversion of Python docstrings to Markdown
LICENSE=	gnu-lgpl-v2.1 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

# as of 0.17
# 5 failed, 106 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
