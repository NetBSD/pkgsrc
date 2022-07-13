# $NetBSD: Makefile,v 1.18 2022/07/13 11:41:06 jperkin Exp $

DISTNAME=	cfscrape-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfscrape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Anorov/cloudflare-scrape
COMMENT=	Python module for dealing with Cloudfare protection
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.6.1:../../devel/py-requests
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
