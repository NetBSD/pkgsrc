# $NetBSD: Makefile,v 1.29 2026/11/08 19:17:02 wiz Exp $

DISTNAME=	soupsieve-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/soupsieve/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facelessuser/soupsieve
COMMENT=	CSS4 selector implementation for Beautiful Soup
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.26:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=0:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-html5lib>=0:../../textproc/py-html5lib
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
