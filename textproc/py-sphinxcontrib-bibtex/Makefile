# $NetBSD: Makefile,v 1.1 2018/07/26 10:37:57 jaapb Exp $

DISTNAME=	sphinxcontrib-bibtex-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-bibtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/sphinxcontrib-bibtex
COMMENT=	Sphinx extension for BibTeX style citations
LICENSE=	2-clause-bsd

USE_LANGUAGES=		# none

DEPENDS+=		py[0-9]*-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
