# $NetBSD: Makefile,v 1.15 2017/09/04 14:45:25 wiz Exp $

DISTNAME=	google-api-python-client-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:C/^${PYPKGPREFIX}-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/google-api-python-client
COMMENT=	Python client library for Google's discovery based APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.9.2:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=1.4.6:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=3:../../textproc/py-uritemplate
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
