# $NetBSD: Makefile,v 1.30 2026/06/12 07:57:09 adam Exp $

DISTNAME=	web_py-0.76
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/web_py/webpy/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/web.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://webpy.org/
COMMENT=	Simple, public domain web publishing system
LICENSE=	public-domain

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cheroot>=6.0.0:../../www/py-cheroot
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=2.6:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-multipart>=0.2.4:../../www/py-multipart

USE_LANGUAGES=	# none

# as of 0.70:
# 57 passed, 132 warnings
# but sometimes (DiskStoreTest.testStoreConcurrent)
# 1 failed, 56 passed, 132 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
