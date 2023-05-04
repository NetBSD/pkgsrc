# $NetBSD: Makefile,v 1.8 2023/05/04 12:45:58 wiz Exp $

DISTNAME=	tzlocal-4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tzlocal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regebro/tzlocal
COMMENT=	Python tzinfo object for the local timezone
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pytz_deprecation_shim-[0-9]*:../../time/py-pytz_deprecation_shim
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
