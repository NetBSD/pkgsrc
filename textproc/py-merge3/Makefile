# $NetBSD: Makefile,v 1.7 2026/11/16 12:28:33 adam Exp $

DISTNAME=	merge3-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/merge3/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/merge3
COMMENT=	Python implementation of 3-way merge
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	merge3

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
