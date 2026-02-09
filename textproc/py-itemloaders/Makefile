# $NetBSD: Makefile,v 1.13 2026/02/09 12:58:47 adam Exp $

DISTNAME=	itemloaders-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itemloaders/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/itemloaders
COMMENT=	Python library that helps to collect data from HTML and XML sources
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-itemadapter>=0.1.0:../../textproc/py-itemadapter
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.9.5:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.5.0:../../www/py-parsel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
