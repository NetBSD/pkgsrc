# $NetBSD: Makefile,v 1.16 2022/05/13 10:57:32 jperkin Exp $

DISTNAME=	cfscrape-2.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfscrape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Anorov/cloudflare-scrape
COMMENT=	Python module for dealing with Cloudfare protection
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.6.1:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
