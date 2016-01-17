# $NetBSD: Makefile,v 1.5 2016/01/17 11:53:30 wiz Exp $

DISTNAME=	cloud_sptheme-${VERSION}
PKGNAME=	${PYPKGPREFIX}-sphinx-theme-cloud-${VERSION}
VERSION=	1.7.1
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/c/cloud_sptheme/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://packages.python.org/cloud_sptheme/
COMMENT=	Sphinx cloud theme
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=	#none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
