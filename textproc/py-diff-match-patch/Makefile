# $NetBSD: Makefile,v 1.9 2024/11/04 08:23:52 adam Exp $

DISTNAME=	diff_match_patch-20241021
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diff-match-patch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/diff-match-patch-python/diff-match-patch
COMMENT=	Robust algorithms for synchronizing plain text
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.8:../../devel/py-flit_core

USE_LANGUAGES=	# none

REPLACE_PYTHON=	diff_match_patch/tests/speedtest.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
