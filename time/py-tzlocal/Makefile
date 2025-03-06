# $NetBSD: Makefile,v 1.16 2025/03/06 08:04:13 adam Exp $

DISTNAME=	tzlocal-5.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tzlocal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regebro/tzlocal
COMMENT=	Python tzinfo object for the local timezone
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.3:../../devel/py-test-mock

USE_LANGUAGES=	# none

# tests need 'make install'
# 3 failed, 17 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
