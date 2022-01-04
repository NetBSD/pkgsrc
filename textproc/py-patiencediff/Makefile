# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:02 wiz Exp $

DISTNAME=	patiencediff-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:source/=90/ca/13cdabb3c491a0ccd7d580419b96abce3d227d4a6ba674364e6b19d4d67e/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://www.breezy-vcs.org/
COMMENT=	Python implementation of the patiencediff algorithm
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # or later

USE_LANGUAGES+=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
