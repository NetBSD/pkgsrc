# $NetBSD: Makefile,v 1.5 2018/01/04 21:31:41 adam Exp $

DISTNAME=	Scrapy-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Scrapy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scrapy.org/
COMMENT=	High-level Web Crawling and Web Scraping framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.1.0:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-pydispatcher>=2.0.5:../../devel/py-pydispatcher
DEPENDS+=	${PYPKGPREFIX}-queuelib-[0-9]*:../../devel/py-queuelib
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted>=13.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.17.0:../../www/py-w3lib

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/scrapy \
		${DESTDIR}${PREFIX}/bin/scrapy${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
