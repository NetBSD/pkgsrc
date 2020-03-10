# $NetBSD: Makefile,v 1.4 2020/03/10 14:51:12 gdt Exp $

DISTNAME=	sphinxcontrib-serializinghtml-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-serializinghtml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sphinx-doc.org/
COMMENT=	Sphinx API for "serialized" HTML files
LICENSE=	2-clause-bsd

# On NetBSD, pax-as-tar fails on this distfile <= 8.  (Accomodate 5-7
# even though they are unsupported.)
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD && !empty(OS_VERSION:M[5678].*)
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
