# $NetBSD: Makefile,v 1.43 2026/10/25 12:49:47 wiz Exp $

DISTNAME=	python_dateutil-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dateutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dateutil/dateutil
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six>=1.5:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.30:../../devel/py-hypothesis

# as of 3.0.0
# 2 failed, 4899 passed, 416 skipped, 17 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
