# $NetBSD: Makefile,v 1.45 2017/08/14 20:00:19 wiz Exp $

DISTNAME=	vdirsyncer-0.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vdirsyncer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log>=0.1.3:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-click-threading>=0.2.0:../../devel/py-click-threading
DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.4.0:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

# tests need DAV_SERVER and REMOTESTORAGE_SERVER environment variables set
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
#BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none
INSTALLATION_DIRS=	share/examples/${PKGBASE}
PLIST_SUBST+=	PKGBASE=${PKGBASE}

PYTHON_VERSIONS_INCOMPATIBLE=	27 # not supported any longer

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
# needed due to py-click
TEST_ENV+=      LC_ALL=en_US.UTF-8
