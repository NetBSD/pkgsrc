# $NetBSD: Makefile,v 1.10 2025/02/23 18:46:49 wiz Exp $

DISTNAME=	diff_match_patch-20241021
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diff-match-patch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/diff-match-patch-python/diff-match-patch
COMMENT=	Robust algorithms for synchronizing plain text
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

REPLACE_PYTHON=	diff_match_patch/tests/speedtest.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
