# $NetBSD: Makefile,v 1.5 2018/12/13 21:13:45 adam Exp $

DISTNAME=	sphinxcontrib-bibtex-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-bibtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/sphinxcontrib-bibtex
COMMENT=	Sphinx extension for BibTeX style citations
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-oset>=0.1.3:../../devel/py-oset
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-pybtex>=0.20:../../textproc/py-pybtex
DEPENDS+=	${PYPKGPREFIX}-pybtex-docutils>=0.2.0:../../textproc/py-pybtex-docutils

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
