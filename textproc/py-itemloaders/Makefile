# $NetBSD: Makefile,v 1.2 2021/03/22 06:14:02 adam Exp $

DISTNAME=	itemloaders-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/itemloaders/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/itemloaders
COMMENT=	Python library that helps to collect data from HTML and XML sources
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-itemadapter>=0.1.0:../../textproc/py-itemadapter
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.9.5:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.5.0:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.17.0:../../www/py-w3lib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
