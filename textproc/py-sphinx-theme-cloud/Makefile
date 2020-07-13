# $NetBSD: Makefile,v 1.10 2020/07/13 20:05:12 wiz Exp $

DISTNAME=	cloud_sptheme-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/cloud_sptheme/sphinx-theme-cloud/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloud_sptheme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ecollins/cloud_sptheme
COMMENT=	Sphinx cloud theme
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES=	sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
