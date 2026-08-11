# $NetBSD: Makefile,v 1.16 2026/08/11 09:24:51 adam Exp $

DISTNAME=	guessit-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guessit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://guessit.readthedocs.io/
COMMENT=	Extracts as much information as possible from a video filename
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.6.1:../../textproc/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-rebulk>=6.0.1:../../textproc/py-rebulk
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	guessit

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
