# $NetBSD: Makefile,v 1.41 2026/08/21 11:21:36 wiz Exp $

DISTNAME=	python-dateutil-2.9.0.post0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//:S/post/0.0./}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dateutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dateutil/dateutil
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six>=1.5:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.30:../../devel/py-hypothesis

# as of 2.9.0.post0
# 31 failed, 2001 passed, 47 skipped, 17 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
