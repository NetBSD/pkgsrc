# $NetBSD: Makefile,v 1.20 2024/10/10 19:47:07 wiz Exp $

DISTNAME=	httpie-3.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpie/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer>=2.0.0:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.6.0:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.7.0:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-rich>=9.10.0:../../comms/py-rich
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin>=0.0.6:../../www/py-test-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-test-lazy-fixture>=0.0.6:../../devel/py-test-lazy-fixture
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing mandir paths.
SUBST_FILES.man=	setup.cfg
SUBST_SED.man+=		-e 's,share/man,${PKGMANDIR},g'

post-install:
.for bin in http httpie https
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	${MV} ${bin}.1 ${bin}-${PYVERSSUFFIX}.1 || ${TRUE}
.endfor

# for tests
ALLOW_NETWORK_ACCESS=1
# test status as of 3.2.3
# 19 failed, 1008 passed, 5 skipped, 4 xfailed, 166 warnings
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
