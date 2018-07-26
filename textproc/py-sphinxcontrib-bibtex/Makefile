# $NetBSD: Makefile,v 1.2 2018/07/26 11:48:18 jaapb Exp $

DISTNAME=	sphinxcontrib-bibtex-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-bibtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/sphinxcontrib-bibtex
COMMENT=	Sphinx extension for BibTeX style citations
LICENSE=	2-clause-bsd

USE_LANGUAGES=		# none

DEPENDS+=		py[0-9]*-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=		py[0-9]*-oset-[0-9]*:../../devel/py-oset

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
