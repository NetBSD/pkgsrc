# $NetBSD: Makefile,v 1.22 2025/04/14 11:57:58 adam Exp $

DISTNAME=	cssutils-2.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssutils/}

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://cthedot.de/cssutils/
COMMENT=	Cascading Style Sheets parser and library for Python
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
TEST_DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.test>=5.1:../../devel/py-jaraco.test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/cssutils/*.py
REPLACE_PYTHON+=	src/cssutils/scripts/*.py

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
.endif

post-install:
.for bin in csscapture csscombine cssparse
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
