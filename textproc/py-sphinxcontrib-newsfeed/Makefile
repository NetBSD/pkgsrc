# $NetBSD: Makefile,v 1.7 2024/08/10 08:01:16 adam Exp $

DISTNAME=	sphinxcontrib-newsfeed-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-newsfeed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/prometheus/sphinxcontrib-newsfeed
COMMENT=	News Feed extension for Sphinx
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39 # py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
