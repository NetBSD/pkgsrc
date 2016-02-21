# $NetBSD: Makefile,v 1.30 2016/02/21 22:26:33 wiz Exp $

DISTNAME=	vdirsyncer-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vdirsyncer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	mit

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log-[0-9]*:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-click-threading-[0-9]*:../../devel/py-click-threading
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.4.0:../../devel/py-requests-toolbelt

# tests need DAV_SERVER and REMOTESTORAGE_SERVER environment variables set
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none
INSTALLATION_DIRS=	share/examples/${PKGBASE}
PLIST_SUBST+=	PKGBASE=${PKGBASE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
