# $NetBSD: Makefile,v 1.11 2025/07/07 05:58:06 wiz Exp $

DISTNAME=	itemloaders-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itemloaders/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/itemloaders
COMMENT=	Python library that helps to collect data from HTML and XML sources
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-itemadapter>=0.1.0:../../textproc/py-itemadapter
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.9.5:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.5.0:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.17.0:../../www/py-w3lib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
