# $NetBSD: Makefile,v 1.2 2025/04/22 20:47:45 wiz Exp $

DISTNAME=	PyBrowserID-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyBrowserID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/PyBrowserID
COMMENT=	Python library for the BrowserID Protocol
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

# as of 0.14.0
# 20 failed, 86 passed, 5 skipped, 416 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
