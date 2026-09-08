# $NetBSD: Makefile,v 1.20 2026/09/08 05:45:32 adam Exp $

DISTNAME=	pyquery-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyquery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gawel/pyquery
COMMENT=	Python jquery-like library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cssselect>=1.5.0:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.1:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest>=0:../../www/py-WebTest
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
