# $NetBSD: Makefile,v 1.1 2017/02/13 21:21:09 adam Exp $

DISTNAME=	parsel-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parsel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/scrapy/parsel
COMMENT=	Library to extract data from HTML and XML using XPath and CSS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-w3lib>=1.8.0:../../www/py-w3lib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
