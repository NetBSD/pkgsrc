# $NetBSD: Makefile,v 1.32 2026/03/02 15:02:50 gdt Exp $

# Before updating sip, geography/qgis (as the most demanding sip user
# currently known) must be tested to build and run (with an actual
# project, loading data).  This is due to a repeated history of
# problematic sip releases.
#
# The 6.8.0 release of sip was very broken.
# In 2025-06, 6.11.1 caused the build of qgis 3.34 to fail.
# In 2025-06, 6.12.0 caused the build of qgis 3.34 and 3.40 to fail.
# (qgis 3.40.8 contained an accommodation for sip's behavior change.)
#
# sip's .0 releases should be viewed with extreme caution and if not
# skipped, deferred until they have been out for 90 days, intended to
# be long enough that any pain will have been taken and reported by
# other packaging systems -- the MAINTAINER's decision is that lack of
# trouble is more important than fast updates.

DISTNAME=	sip-6.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip6/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sip/}
# Upstream NEWS is not in NEWS, but instead at:
#   https://python-sip.readthedocs.io/en/stable/releases.html

MAINTAINER=	gdt@NetBSD.org
#MAINTAINER+=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/Python-SIP/sip
COMMENT=	Tool to create Python bindings for C++ libraries
LICENSE=	sip-license OR gnu-gpl-v2 OR gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

# Tests are broken; the file downloadable from pypi omits them.
# https://github.com/Python-SIP/sip/issues/103
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-anyio-[0-9]*:../../devel/py-anyio

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
