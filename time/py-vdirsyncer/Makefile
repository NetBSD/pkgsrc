# $NetBSD: Makefile,v 1.68 2023/11/07 22:38:08 wiz Exp $

DISTNAME=	vdirsyncer-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vdirsyncer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=0.1.7:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-log>=0.3.0:../../devel/py-click-log
DEPENDS+=	${PYPKGPREFIX}-click-threading>=0.5:../../devel/py-click-threading
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.4.0:../../devel/py-requests-toolbelt
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.0.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver

USE_LANGUAGES=		# none
INSTALLATION_DIRS=	share/examples/${PKGBASE} ${PKGMANDIR}/man1
PLIST_SUBST+=		PKGBASE=${PKGBASE}

PYTHON_SELF_CONFLICT=	yes
PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

USE_TOOLS+=	gmake

post-build:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} PYTHONPATH=${WRKSRC} ${GMAKE} man SPHINXBUILD=sphinx-build-${PYVERSSUFFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/vdirsyncer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
# needed due to py-click
TEST_ENV+=      LC_ALL=en_US.UTF-8
