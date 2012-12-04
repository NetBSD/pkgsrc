# $NetBSD: Makefile,v 1.1 2012/12/04 15:19:52 darcy Exp $


DISTNAME=	cloud_sptheme-${VERSION}
PKGNAME=    ${PYPKGPREFIX}sphinx-theme-cloud-${VERSION}
VERSION=    1.5
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/c/cloud_sptheme/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://packages.python.org/cloud_sptheme/
COMMENT=	Sphinx cloud theme
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx:../../textproc/py-sphinx

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
