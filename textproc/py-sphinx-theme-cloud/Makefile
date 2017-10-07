# $NetBSD: Makefile,v 1.7 2017/10/07 11:25:00 adam Exp $

DISTNAME=	cloud_sptheme-1.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/cloud_sptheme/sphinx-theme-cloud/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloud_sptheme/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ecollins/cloud_sptheme
COMMENT=	Sphinx cloud theme
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
