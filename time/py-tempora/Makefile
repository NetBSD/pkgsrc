# $NetBSD: Makefile,v 1.27 2024/12/31 17:56:53 adam Exp $

DISTNAME=	tempora-5.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tempora/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/tempora
COMMENT=	Objects and routines pertaining to date and time
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=1.20:../../devel/py-jaraco.functools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer-[0-9]*:../../devel/py-test-freezer

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} calc-prorate calc-prorate-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
