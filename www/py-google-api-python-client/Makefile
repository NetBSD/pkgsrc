# $NetBSD: Makefile,v 1.46 2022/01/27 11:57:26 wiz Exp $

DISTNAME=	google-api-python-client-2.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-python-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-api-python-client
COMMENT=	Python client library for Google's discovery based APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-api-core>=1.21.0:../../devel/py-google-api-core
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.16.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth-httplib2>=0.1.0:../../security/py-google-auth-httplib2
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.15.0:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-six>=1.13.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=3.0.0:../../textproc/py-uritemplate
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-oauth2client-[0-9]*:../../security/py-oauth2client
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# unittest2 is a replacement for python 2.x for unittest; this package
# is limited to python 3.x anyway, so use unittest directly
SUBST_CLASSES+=		unittest
SUBST_STAGE.unittest=	pre-build
SUBST_MESSAGE.unittest=	Removing unittest2 dependency
SUBST_SED.unittest+=	-e 's/import unittest2 as unittest/import unittest/'
SUBST_FILES.unittest+=	tests/test*.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
