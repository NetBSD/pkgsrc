# $NetBSD: Makefile,v 1.44 2026/11/08 17:45:39 wiz Exp $

DISTNAME=	python_dateutil-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dateutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dateutil/dateutil
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.30:../../devel/py-hypothesis

# as of 4.0.0
# 38 failed, 4875 passed, 414 skipped, 17 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
