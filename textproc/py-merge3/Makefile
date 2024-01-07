# $NetBSD: Makefile,v 1.1 2024/01/07 15:57:02 rhialto Exp $

DISTNAME=	merge3-0.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:source/=af/40/98be4a5641b0244be5881ff5e00057f8227ff183d8675a697bdfeae43b1a/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.breezy-vcs.org/
COMMENT=	Python implementation of 3-way merge
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
