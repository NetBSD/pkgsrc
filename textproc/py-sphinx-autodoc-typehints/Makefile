# $NetBSD: Makefile,v 1.1 2018/05/27 01:59:35 minskim Exp $

DISTNAME=	sphinx-autodoc-typehints-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autodoc-typehints/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/sphinx-autodoc-typehints
COMMENT=	Type hints support for the Sphinx autodoc extension
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.4:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.1.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py34"
DEPENDS+=	${PYPKGPREFIX}-typing>=3.5:../../devel/py-typing
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
