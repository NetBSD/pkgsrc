# $NetBSD: Makefile,v 1.3 2024/01/07 16:33:50 rhialto Exp $

DISTNAME=	patiencediff-0.2.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:source/=57/9f/0973293d232696ae191cef7c4e8eb1ebbdb7728c48662ebf04c26fd576e4/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.breezy-vcs.org/
COMMENT=	Python implementation of the patiencediff algorithm
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

USE_LANGUAGES+=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
