# $NetBSD: Makefile,v 1.2 2018/02/05 15:05:02 jperkin Exp $

DISTNAME=	google-apitools-0.5.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-apitools/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/google/apitools
COMMENT=	Client libraries for humans
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-fasteners>=0.14:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-gflags>=3.0.6:../../devel/py-gflags
DEPENDS+=	${PYPKGPREFIX}-google-apputils>=0.4.0:../../devel/py-google-apputils
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.8:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=2.1.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

# Test dependencies:
DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.5.1:../../devel/py-unittest2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-google-apputils

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/requires.txt.orig
do-test:
	cd ${WRKSRC} && nosetests-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
