# $NetBSD: Makefile,v 1.59 2023/11/10 12:14:53 adam Exp $

DISTNAME=	google-api-python-client-2.107.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-python-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-api-python-client
COMMENT=	Python client library for Google's discovery based APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-api-core>=2.3.1:../../devel/py-google-api-core
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.19.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth-httplib2>=0.1.0:../../security/py-google-auth-httplib2
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.15.0:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=3.0.1:../../textproc/py-uritemplate
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
