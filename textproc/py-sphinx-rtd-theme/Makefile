# $NetBSD: Makefile,v 1.16 2023/11/07 22:38:06 wiz Exp $

DISTNAME=	sphinx_rtd_theme-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx_rtd_theme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtfd/sphinx_rtd_theme
COMMENT=	Sphinx readthedocs.org theme
LICENSE=	mit AND apache-2.0

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jquery>=4.0.0:../../textproc/py-sphinxcontrib-jquery
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
