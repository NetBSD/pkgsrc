# $NetBSD: Makefile,v 1.2 2017/09/04 18:08:29 wiz Exp $

DISTNAME=	sphinxcontrib-newsfeed-0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-newsfeed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/prometheus/sphinxcontrib-newsfeed
COMMENT=	News Feed extension for Sphinx
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
