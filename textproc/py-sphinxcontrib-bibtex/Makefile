# $NetBSD: Makefile,v 1.4 2018/07/27 07:28:14 jperkin Exp $

DISTNAME=	sphinxcontrib-bibtex-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-bibtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/sphinxcontrib-bibtex
COMMENT=	Sphinx extension for BibTeX style citations
LICENSE=	2-clause-bsd

USE_LANGUAGES=		# none

DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=		${PYPKGPREFIX}-oset-[0-9]*:../../devel/py-oset

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
