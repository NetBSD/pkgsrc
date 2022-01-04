# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:54 wiz Exp $

DISTNAME=	diff-match-patch-20200713
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diff-match-patch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/diff-match-patch-python/diff-match-patch
COMMENT=	Robust algorithms for synchronizing plain text
LICENSE=	apache-2.0

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools:build

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
do-test:
.if ${_PYTHON_VERSION} == 27
	cd ${WRKSRC} && ${PYTHONBIN} diff_match_patch/tests/diff_match_patch_test_py2.py
.else
	cd ${WRKSRC} && ${PYTHONBIN} diff_match_patch/tests/diff_match_patch_test.py
.endif

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
