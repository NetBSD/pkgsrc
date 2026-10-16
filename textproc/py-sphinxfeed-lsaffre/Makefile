# $NetBSD: Makefile,v 1.4 2026/10/16 19:44:23 adam Exp $

DISTNAME=	sphinxfeed_lsaffre-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxfeed_lsaffre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lsaffre/sphinxfeed
COMMENT=	Automatically generates an RSS feed when a build is run
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-feedgen>=0:../../www/py-feedgen
DEPENDS+=	${PYPKGPREFIX}-sphinx>=0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
