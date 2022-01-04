# $NetBSD: Makefile,v 1.8 2022/01/04 20:55:06 wiz Exp $

DISTNAME=	sphinxcontrib-bibtex-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-bibtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/sphinxcontrib-bibtex
COMMENT=	Sphinx extension for BibTeX style citations
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-oset>=0.1.3:../../devel/py-oset
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-pybtex>=0.20:../../textproc/py-pybtex
DEPENDS+=	${PYPKGPREFIX}-pybtex-docutils>=0.2.0:../../textproc/py-pybtex-docutils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
