# $NetBSD: Makefile,v 1.15 2022/01/04 20:55:17 wiz Exp $

DISTNAME=	cfscrape-2.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfscrape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Anorov/cloudflare-scrape
COMMENT=	Python module for dealing with Cloudfare protection
LICENSE=	mit

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs
DEPENDS+=	${PYPKGPREFIX}-requests>=2.6.1:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
