# $NetBSD: Makefile,v 1.48 2024/02/15 22:23:43 wiz Exp $

DISTNAME=	CherryPy-18.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CherryPy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cherrypy.dev/
COMMENT=	Pythonic, object-oriented HTTP framework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cheroot>=8.2.1:../../www/py-cheroot
DEPENDS+=	${PYPKGPREFIX}-jaraco.collections-[0-9]*:../../devel/py-jaraco.collections
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-portend>=2.1.1:../../net/py-portend
DEPENDS+=	${PYPKGPREFIX}-zc.lockfile-[0-9]*:../../devel/py-zc.lockfile
# json
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-objgraph-[0-9]*:../../graphics/py-objgraph
TEST_DEPENDS+=	${PYPKGPREFIX}-path.py-[0-9]*:../../devel/py-path.py
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt-[0-9]*:../../devel/py-requests-toolbelt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-forked-[0-9]*:../../devel/py-test-forked
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cherryd cherryd-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
