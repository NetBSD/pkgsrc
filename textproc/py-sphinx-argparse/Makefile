# $NetBSD: Makefile,v 1.3 2025/12/28 21:22:50 wiz Exp $

DISTNAME=	sphinx_argparse-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-argparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sphinx-argparse.readthedocs.io/
COMMENT=	Sphinx extension that automatically documents argparse commands and options
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=0:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-sphinx>=5.1.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.19:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-sphinx

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/sphinxarg/ext.py.orig

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
