# $NetBSD: Makefile,v 1.34 2016/05/06 07:07:05 wiz Exp $

DISTNAME=	vdirsyncer-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	https://pypi.python.org/packages/0b/fb/c42223e1e9169e4770194e62143d431755724b080d8cb77f14705b634815/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	mit

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log>=0.1.3:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-click-threading-[0-9]*:../../devel/py-click-threading
DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.4.0:../../devel/py-requests-toolbelt

# tests need DAV_SERVER and REMOTESTORAGE_SERVER environment variables set
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
#BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none
INSTALLATION_DIRS=	share/examples/${PKGBASE}
PLIST_SUBST+=	PKGBASE=${PKGBASE}

PYTHON_VERSIONS_INCOMPATIBLE=	27 # still supported but gives runtime warning
# see https://github.com/pimutils/vdirsyncer/issues/219

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
