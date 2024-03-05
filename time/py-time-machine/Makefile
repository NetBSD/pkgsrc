# $NetBSD: Makefile,v 1.4 2024/03/05 17:07:59 adam Exp $

DISTNAME=	time-machine-2.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/time-machine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamchainz/time-machine
COMMENT=	Travel through time in your tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
