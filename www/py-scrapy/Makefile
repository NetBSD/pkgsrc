# $NetBSD: Makefile,v 1.16 2022/10/19 14:25:20 nia Exp $

DISTNAME=	Scrapy-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Scrapy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scrapy.org/
COMMENT=	High-level Web Crawling and Web Scraping framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.1.3:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9.1:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-itemloaders>=1.0.1:../../textproc/py-itemloaders
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.5.0:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-protego>=0.1.15:../../www/py-protego
DEPENDS+=	${PYPKGPREFIX}-pydispatcher>=2.0.5:../../devel/py-pydispatcher
DEPENDS+=	${PYPKGPREFIX}-queuelib>=1.4.2:../../devel/py-queuelib
DEPENDS+=	${PYPKGPREFIX}-service_identity>=16.0.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.17.0:../../www/py-w3lib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} scrapy scrapy-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
