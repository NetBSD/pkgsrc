# $NetBSD: Makefile,v 1.6 2017/12/21 08:08:13 adam Exp $

DISTNAME=	cfscrape-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfscrape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Anorov/cloudflare-scrape
COMMENT=	Python module for dealing with Cloudfare protection
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-execjs>=1.4.0:../../lang/py-execjs
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
