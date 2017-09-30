# $NetBSD: Makefile,v 1.3 2017/09/30 13:27:14 adam Exp $

DISTNAME=	w3lib-1.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/w3lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scrapy/w3lib
COMMENT=	Python library of web-related functions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
