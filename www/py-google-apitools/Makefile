# $NetBSD: Makefile,v 1.6 2020/06/04 06:25:17 adam Exp $

DISTNAME=	google-apitools-0.5.31
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-apitools/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/google/apitools
COMMENT=	Client libraries for humans
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-fasteners>=0.14:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-gflags>=3.0.6:../../devel/py-gflags
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.8:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=2.1.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.5.1:../../devel/py-unittest2

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} gen_client gen_client-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && nosetests-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
