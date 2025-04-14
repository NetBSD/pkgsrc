# $NetBSD: Makefile,v 1.29 2025/04/14 20:28:03 adam Exp $

DISTNAME=	webpy-0.70
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/webpy/web.py/}
PKGREVISION=	1
CATEGORIES=	www python
# 0.62 is latest on pypi
#MASTER_SITES=	${MASTER_SITE_PYPI:=w/web.py/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=webpy/}
GITHUB_PROJECT=	webpy
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://webpy.org/
COMMENT=	Simple, public domain web publishing system
LICENSE=	public-domain

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cheroot>=6.0.0:../../www/py-cheroot
DEPENDS+=	${PYPKGPREFIX}-multipart>=0:../../www/py-multipart

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/web/web_/}

# as of 0.70:
# 57 passed, 132 warnings
# but sometimes (DiskStoreTest.testStoreConcurrent)
# 1 failed, 56 passed, 132 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
