# $NetBSD: Makefile,v 1.8 2019/01/31 09:07:46 adam Exp $

DISTNAME=	Scrapy-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Scrapy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scrapy.org/
COMMENT=	High-level Web Crawling and Web Scraping framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13.1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.5:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-pydispatcher>=2.0.5:../../devel/py-pydispatcher
DEPENDS+=	${PYPKGPREFIX}-queuelib>=1.1.1:../../devel/py-queuelib
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.17.0:../../www/py-w3lib

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} scrapy scrapy-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
