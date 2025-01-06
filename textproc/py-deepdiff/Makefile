# $NetBSD: Makefile,v 1.19 2025/01/06 10:30:17 adam Exp $

DISTNAME=	deepdiff-8.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-orderly-set>=5.2.3:../../devel/py-orderly-set
# cli
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.2:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.23.5:../../math/py-numpy

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} deep deep-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
