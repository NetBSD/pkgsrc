# $NetBSD: Makefile,v 1.3 2018/06/16 20:31:12 bsiegert Exp $

DISTNAME=	google-apitools-0.5.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-apitools/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/google/apitools
COMMENT=	Client libraries for humans
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-fasteners>=0.14:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-gflags>=3.0.6:../../devel/py-gflags
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.8:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=2.1.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

# Test dependencies:
DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.5.1:../../devel/py-unittest2

do-test:
	cd ${WRKSRC} && nosetests-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
