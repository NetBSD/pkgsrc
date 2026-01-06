# $NetBSD: Makefile,v 1.1 2026/01/06 18:49:19 adam Exp $

DISTNAME=	changelog_chug-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/changelog-chug/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~bignose/changelog-chug
COMMENT=	Parser library for project Change Log documents
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.21.0:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-semver>=3.0.0:../../devel/py-semver
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.4:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools>0:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
