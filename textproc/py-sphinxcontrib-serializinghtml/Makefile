# $NetBSD: Makefile,v 1.5 2020/03/10 23:07:58 gdt Exp $

DISTNAME=	sphinxcontrib-serializinghtml-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-serializinghtml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sphinx-doc.org/
COMMENT=	Sphinx API for "serialized" HTML files
LICENSE=	2-clause-bsd

# On NetBSD <= 8, pax-as-tar fails on this distfile.  Use bsdtar
# (which on 9 and up will use base tar, if it's libarchive tar).
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
EXTRACT_USING=	bsdtar
.endif

TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-sphinx

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
