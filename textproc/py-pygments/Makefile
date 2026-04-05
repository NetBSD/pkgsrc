# $NetBSD: Makefile,v 1.55 2026/04/05 07:30:32 wiz Exp $

DISTNAME=	pygments-2.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-wcag-contrast-ratio-[0-9]*:../../graphics/py-wcag-contrast-ratio
#
# py-test pulls in py-pygments, so make sure to 'make install'
# before installing test dependencies

USE_LANGUAGES=	# none

PY_RENAME_BINARIES+=	pygmentize

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
