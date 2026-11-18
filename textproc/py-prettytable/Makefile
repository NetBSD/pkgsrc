# $NetBSD: Makefile,v 1.43 2026/11/18 09:07:37 adam Exp $

DISTNAME=	prettytable-3.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prettytable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prettytable/prettytable
COMMENT=	Display tabular data in a visually appealing ASCII table format
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.3.5:../../devel/py-wcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-lazy-fixtures>=0:../../devel/py-test-lazy-fixtures

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
