# $NetBSD: Makefile,v 1.5 2022/07/10 19:05:02 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
