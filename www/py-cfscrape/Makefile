# $NetBSD: Makefile,v 1.3 2017/08/16 18:04:34 adam Exp $

DISTNAME=	cfscrape-1.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfscrape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/cfscrape/
COMMENT=	Python module for dealing with Cloudfare protection
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-execjs>=1.4.0:../../lang/py-execjs
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
