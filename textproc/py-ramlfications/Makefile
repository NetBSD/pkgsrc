# $NetBSD: Makefile,v 1.13 2026/11/10 09:23:50 adam Exp $

DISTNAME=	ramlfications-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ramlfications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ramlfications.readthedocs.io/
COMMENT=	Python RAML parser
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-inflect>=0:../../lang/py-inflect
DEPENDS+=	${PYPKGPREFIX}-jsonref>=0:../../textproc/py-jsonref
DEPENDS+=	${PYPKGPREFIX}-markdown2>=0:../../textproc/py-markdown2
DEPENDS+=	${PYPKGPREFIX}-termcolor>=0:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver>=0:../../devel/py-test-localserver

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	ramlfications

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
