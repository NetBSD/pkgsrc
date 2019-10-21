# $NetBSD: Makefile,v 1.8 2019/10/21 22:01:06 adam Exp $

DISTNAME=	cloud_sptheme-1.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/cloud_sptheme/sphinx-theme-cloud/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloud_sptheme/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ecollins/cloud_sptheme
COMMENT=	Sphinx cloud theme
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES=	sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
