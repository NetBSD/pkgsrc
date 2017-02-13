# $NetBSD: Makefile,v 1.1 2017/02/13 21:19:51 adam Exp $

DISTNAME=	w3lib-1.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/w3lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/scrapy/w3lib
COMMENT=	Python library of web-related functions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
