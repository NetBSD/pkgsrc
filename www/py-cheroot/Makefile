# $NetBSD: Makefile,v 1.20 2018/09/03 07:58:51 adam Exp $

DISTNAME=	cheroot-6.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/Cheroot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	High-performance, pure-Python HTTP server used by CherryPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-more-itertools>=2.6:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm_git_archive>=1.0:../../devel/py-setuptools_scm_git_archive
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-portend-[0-9]*:../../net/py-portend
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-test-testmon>=0.9.7:../../devel/py-test-testmon

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache-[0-9]*:../../devel/py-backports.functools_lru_cache
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cheroot cheroot-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
