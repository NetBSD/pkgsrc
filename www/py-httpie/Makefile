# $NetBSD: Makefile,v 1.14 2022/10/25 07:59:07 adam Exp $

DISTNAME=	httpie-3.2.1
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpie/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/jakubroztocil/httpie
COMMENT=	Human-friendly command line HTTP client
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-charset-normalizer>=2.0.0:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
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

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} == 37
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=1.4.0:../../devel/py-importlib-metadata
.endif

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing mandir paths.
SUBST_FILES.man=	setup.py
SUBST_SED.man+=		-e 's,share/man,${PKGMANDIR},g'

post-install:
.for bin in http httpie https
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	${MV} ${bin}.1 ${bin}-${PYVERSSUFFIX}.1 || ${TRUE}
.endfor

# test status as of 3.1.0
# 12 failed, 966 passed, 6 skipped, 1 xfailed, 327 warnings
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
