# $NetBSD: Makefile,v 1.13 2025/12/01 13:25:47 adam Exp $

DISTNAME=	time_machine-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/time-machine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamchainz/time-machine
COMMENT=	Travel through time in your tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# dateutil
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
