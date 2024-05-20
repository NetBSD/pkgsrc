# $NetBSD: Makefile,v 1.2 2024/05/20 10:10:17 wiz Exp $

DISTNAME=	PyFxA-0.7.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyFxA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/PyFxA
COMMENT=	Firefox Accounts client library for Python
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-BrowserID>=0:../../www/py-BrowserID
DEPENDS+=	${PYPKGPREFIX}-JWT>=0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-hawkauthlib>=0:../../security/py-hawkauthlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.14:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-grequests>=0:../../net/py-grequests
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.6.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner>=4.5.1:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8>=0:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-otp>=0:../../security/py-otp

USE_LANGUAGES=	# none
USE_TOOLS+=	ftp:test

PYTHON_VERSIONS_INCOMPATIBLE=	27

# test status as of 0.7.8
# 18 failed, 97 passed, 1 skipped, 1 warning
# https://github.com/mozilla/PyFxA/issues/95

# missing files in distfile
pre-test:
	cd ${WRKSRC}/fxa/tests && ftp https://raw.githubusercontent.com/mozilla/PyFxA/main/fxa/tests/bad-key.json
	cd ${WRKSRC}/fxa/tests && ftp https://raw.githubusercontent.com/mozilla/PyFxA/main/fxa/tests/jwks.json
	cd ${WRKSRC}/fxa/tests && ftp https://raw.githubusercontent.com/mozilla/PyFxA/main/fxa/tests/private-key.json

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
