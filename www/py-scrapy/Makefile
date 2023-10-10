# $NetBSD: Makefile,v 1.20 2023/10/10 17:18:23 triaxx Exp $

DISTNAME=	Scrapy-2.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Scrapy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scrapy.org/
COMMENT=	High-level Web Crawling and Web Scraping framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5.1.0:../../devel/py-zope.interface
DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9.1:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-itemadapter>=0.1.0:../../textproc/py-itemadapter
DEPENDS+=	${PYPKGPREFIX}-itemloaders>=1.0.1:../../textproc/py-itemloaders
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.5.0:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-protego>=0.1.15:../../www/py-protego
DEPENDS+=	${PYPKGPREFIX}-pydispatcher>=2.0.5:../../devel/py-pydispatcher
DEPENDS+=	${PYPKGPREFIX}-queuelib>=1.4.2:../../devel/py-queuelib
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-tldextract-[0-9]*:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-twisted>=18.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.17.0:../../www/py-w3lib

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} scrapy scrapy-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
