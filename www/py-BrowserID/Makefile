# $NetBSD: Makefile,v 1.1 2023/06/11 07:58:21 wiz Exp $

DISTNAME=	PyBrowserID-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyBrowserID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/PyBrowserID
COMMENT=	Python library for the BrowserID Protocol
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
