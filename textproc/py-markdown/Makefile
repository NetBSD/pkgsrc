# $NetBSD: Makefile,v 1.52 2026/11/06 10:38:17 adam Exp $

DISTNAME=	markdown-3.11.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markdown/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://Python-Markdown.github.io/
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	markdown_py

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
