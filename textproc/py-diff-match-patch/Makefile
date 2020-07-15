# $NetBSD: Makefile,v 1.3 2020/07/15 14:10:14 adam Exp $

DISTNAME=	diff-match-patch-20200713
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diff-match-patch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/diff-match-patch-python/diff-match-patch
COMMENT=	Robust algorithms for synchronizing plain text
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools>=38.6.0:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
do-test:
.if ${_PYTHON_VERSION} == 27
	cd ${WRKSRC} && ${PYTHONBIN} diff_match_patch/tests/diff_match_patch_test_py2.py
.else
	cd ${WRKSRC} && ${PYTHONBIN} diff_match_patch/tests/diff_match_patch_test.py
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
