# $NetBSD: Makefile,v 1.15 2025/01/20 13:25:04 adam Exp $

DISTNAME=	parsel-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parsel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/parsel
COMMENT=	Library to extract data from HTML and XML using XPath and CSS
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cssselect>=1.2.0:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-jmespath-[0-9]*:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.19.0:../../www/py-w3lib
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.6.3:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
