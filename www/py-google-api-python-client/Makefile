# $NetBSD: Makefile,v 1.26 2019/06/11 12:24:41 wiz Exp $

DISTNAME=	google-api-python-client-1.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-api-python-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/google-api-python-client
COMMENT=	Python client library for Google's discovery based APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.9.2:../../www/py-httplib2
# use google-auth instead? (unpackaged)
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=1.5.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=3.0.0:../../textproc/py-uritemplate
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

# https://github.com/googleapis/google-api-python-client/pull/603/commits/31c468787f91eb047bc11b388e2b1b8e9be2df8a
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
