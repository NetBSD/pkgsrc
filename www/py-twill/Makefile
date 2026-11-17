# $NetBSD: Makefile,v 1.33 2026/11/17 08:41:45 adam Exp $

DISTNAME=	twill-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twill-tools/twill
COMMENT=	Simple scripting language for web browsing
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.28.1:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-lxml>=6:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.1:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=3.0:../../www/py-flask
#TEST_DEPENDS+=	${PYPKGPREFIX}-pytidylib>=0.3
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=4:../../devel/py-tox

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	twill twill-fork

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
