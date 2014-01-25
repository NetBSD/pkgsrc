# $NetBSD: Makefile,v 1.3 2014/01/25 10:30:25 wiz Exp $

DISTNAME=	cloud_sptheme-${VERSION}
PKGNAME=	${PYPKGPREFIX}sphinx-theme-cloud-${VERSION}
VERSION=	1.5
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
