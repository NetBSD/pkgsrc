# $NetBSD: Makefile,v 1.8 2024/11/11 07:29:13 wiz Exp $

DISTNAME=	ligotimegps-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ligotimegps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gwpy/ligotimegps
COMMENT=	Pure-python version of lal.LIGOTimeGPS
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
