# $NetBSD: Makefile,v 1.7 2021/04/27 04:53:45 adam Exp $

DISTNAME=	Pyphen-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pyphen/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://pyphen.org/
COMMENT=	Pure Python module to hyphenate text
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
