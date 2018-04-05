# $NetBSD: Makefile,v 1.10 2018/04/05 08:21:03 adam Exp $

DISTNAME=	cfscrape-1.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfscrape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Anorov/cloudflare-scrape
COMMENT=	Python module for dealing with Cloudfare protection
LICENSE=	mit

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
