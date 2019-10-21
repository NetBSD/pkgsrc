# $NetBSD: Makefile,v 1.1 2019/10/21 20:40:11 adam Exp $

DISTNAME=	sphinxcontrib-devhelp-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-devhelp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sphinx-doc.org/
COMMENT=	Sphinx API for Devhelp document
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-sphinx

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
