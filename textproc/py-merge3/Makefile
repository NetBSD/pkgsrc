# $NetBSD: Makefile,v 1.2 2024/01/07 16:03:46 wiz Exp $

DISTNAME=	merge3-0.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/merge3/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.breezy-vcs.org/
COMMENT=	Python implementation of 3-way merge
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
