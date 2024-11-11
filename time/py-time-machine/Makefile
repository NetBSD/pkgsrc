# $NetBSD: Makefile,v 1.9 2024/11/11 07:29:13 wiz Exp $

DISTNAME=	time_machine-2.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/time-machine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamchainz/time-machine
COMMENT=	Travel through time in your tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
