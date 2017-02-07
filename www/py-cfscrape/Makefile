# $NetBSD: Makefile,v 1.1 2017/02/07 23:52:16 joerg Exp $

DISTNAME=	cfscrape-1.6.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www net
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cfscrape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/cfscrape/
COMMENT=	Python module for dealing with Cloudfare protection
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-js2py-[0-9]*:../../lang/py-js2py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
