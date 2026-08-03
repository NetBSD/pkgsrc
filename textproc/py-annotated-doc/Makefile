# $NetBSD: Makefile,v 1.2 2026/08/03 17:26:46 wiz Exp $

DISTNAME=	annotated_doc-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/annotated-doc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastapi/annotated-doc
COMMENT=	Document parameters, class attributes, return types, and variables
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>0:../../devel/py-pdm_backend
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.6.1:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-typer>=0:../../devel/py-typer
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=1.14.1:../../lang/py-mypy

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
