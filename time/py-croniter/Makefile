# $NetBSD: Makefile,v 1.2 2026/04/10 09:59:24 adam Exp $

DISTNAME=	croniter-6.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/croniter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets-eco/croniter
COMMENT=	Iteration for datetime object with cron like format
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.29.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>2021.1:../../time/py-pytz

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/croniter/tests/test_*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
