# $NetBSD: Makefile,v 1.5 2025/04/14 12:39:20 adam Exp $

DISTNAME=	merge3-0.0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/merge3/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/merge3
COMMENT=	Python implementation of 3-way merge
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
