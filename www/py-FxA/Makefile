# $NetBSD: Makefile,v 1.4 2024/10/12 08:41:09 wiz Exp $

DISTNAME=	pyfxa-0.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyfxa/PyFxa/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfxa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/PyFxA
COMMENT=	Firefox Accounts client library for Python
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-BrowserID>=0:../../www/py-BrowserID
DEPENDS+=	${PYPKGPREFIX}-JWT>=0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-hawkauthlib>=0:../../security/py-hawkauthlib
TEST_DEPENDS+=	${PYPKGPREFIX}-grequests>=0:../../net/py-grequests
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized>=0:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-otp>=0:../../security/py-otp

USE_LANGUAGES=	# none

# test status as of 0.7.9
# 126 passed, 14 skipped, 2 warnings
ALLOW_NETWORK_ACCESS=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
