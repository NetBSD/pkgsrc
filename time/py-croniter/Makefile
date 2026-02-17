# $NetBSD: Makefile,v 1.1 2026/02/17 21:53:33 wiz Exp $

DISTNAME=	croniter-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/croniter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets-eco/croniter
COMMENT=	Iteration for datetime object with cron like format
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pytz>2021.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
