# $NetBSD: Makefile,v 1.2 2017/03/19 22:59:10 adam Exp $

DISTNAME=	Scrapy-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Scrapy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scrapy.org/
COMMENT=	High-level Web Crawling and Web Scraping framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-queuelib-[0-9]*:../../devel/py-queuelib
DEPENDS+=	${PYPKGPREFIX}-parsel>=1.1.0:../../www/py-parsel
DEPENDS+=	${PYPKGPREFIX}-pydispatcher>=2.0.5:../../devel/py-pydispatcher
DEPENDS+=	${PYPKGPREFIX}-twisted>=13.1.0:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
