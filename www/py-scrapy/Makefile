# $NetBSD: Makefile,v 1.43 2026/09/03 08:35:37 adam Exp $

DISTNAME=	scrapy-2.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Scrapy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scrapy.org/
COMMENT=	High-level Web Crawling and Web Scraping framework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=24.3.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.2.0:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-cryptography>=41.0.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9.1:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-itemadapter>=0.1.0:../../textproc/py-itemadapter
DEPENDS+=	${PYPKGPREFIX}-itemloaders>=1.0.1:../../textproc/py-itemloaders
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.5.0:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-protego>=0.1.15:../../www/py-protego
DEPENDS+=	${PYPKGPREFIX}-pydispatcher>=2.0.5:../../devel/py-pydispatcher
DEPENDS+=	${PYPKGPREFIX}-queuelib>=1.6.1:../../devel/py-queuelib
DEPENDS+=	${PYPKGPREFIX}-service_identity>=24.2.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-tldextract>=0:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-twisted>=21.7.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-w3lib>=2.1.1:../../www/py-w3lib
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5.1.0:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect>=0:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-sybil>=0:../../devel/py-sybil
TEST_DEPENDS+=	${PYPKGPREFIX}-testfixtures>=0:../../devel/py-testfixtures

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	scrapy

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 314
DEPENDS+=	${PYPKGPREFIX}-backports.zstd>=1.3.0:../../archivers/py-backports.zstd
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
