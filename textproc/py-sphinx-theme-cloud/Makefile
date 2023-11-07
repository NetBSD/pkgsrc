# $NetBSD: Makefile,v 1.13 2023/11/07 22:38:06 wiz Exp $

DISTNAME=	cloud_sptheme-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/cloud_sptheme/sphinx-theme-cloud/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloud_sptheme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ecollins/cloud_sptheme
COMMENT=	Sphinx cloud theme
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
