# $NetBSD: Makefile,v 1.30 2026/05/12 09:29:53 adam Exp $

DISTNAME=	tempora-5.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tempora/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/tempora
COMMENT=	Objects and routines pertaining to date and time
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jaraco.collections>=5.2.1:../../devel/py-jaraco.collections
DEPENDS+=	${PYPKGPREFIX}-jaraco.context>=0:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=4.2:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=0:../../devel/py-more-itertools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer>=0:../../devel/py-test-freezer

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	calc-prorate

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
