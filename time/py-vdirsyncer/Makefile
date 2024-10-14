# $NetBSD: Makefile,v 1.71 2024/10/14 06:46:05 wiz Exp $

DISTNAME=	vdirsyncer-0.19.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vdirsyncer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=0.1.7:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log>=0.3.0:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiostream>=0.4.3:../../devel/py-aiostream
DEPENDS+=	${PYPKGPREFIX}-aiohttp-oauthlib-[0-9]*:../../www/py-aiohttp-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.0.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-aioresponses>=0:../../net/py-aioresponses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver-[0-9]*:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=		# none
INSTALLATION_DIRS=	share/examples/${PKGBASE} ${PKGMANDIR}/man1
PLIST_SUBST+=		PKGBASE=${PKGBASE}

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	39 # py-sphinx

USE_TOOLS+=	gmake

# test status as of 0.19.3
# 409 passed, 160 skipped, 2 xfailed, 7 warnings

post-build:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} PYTHONPATH=${WRKSRC} ${GMAKE} man SPHINXBUILD=sphinx-build-${PYVERSSUFFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/vdirsyncer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
