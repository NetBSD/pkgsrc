# $NetBSD: Makefile,v 1.11 2024/05/22 09:03:56 adam Exp $

DISTNAME=	python_docx-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-docx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openxml/python-docx
COMMENT=	Python library for Microsoft Word (.docx) files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.1.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.9.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-behave>=1.2.3:../../devel/py-behave
TEST_DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.1:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-ruff-[0-9]*:../../devel/py-ruff

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
