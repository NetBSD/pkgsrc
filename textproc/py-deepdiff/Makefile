# $NetBSD: Makefile,v 1.16 2024/05/27 10:28:40 adam Exp $

DISTNAME=	deepdiff-7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-ordered-set>=4.1.0:../../devel/py-ordered-set
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.23.5:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} deep deep-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
