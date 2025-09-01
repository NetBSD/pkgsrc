# $NetBSD: Makefile,v 1.36 2025/09/01 12:59:11 adam Exp $

DISTNAME=	humanize-4.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/humanize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-humanize/humanize
COMMENT=	Convert numbers into easily readable format
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
