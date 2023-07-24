# $NetBSD: Makefile,v 1.14 2023/07/24 18:53:11 adam Exp $

DISTNAME=	respx-0.20.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/respx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lundberg/respx
COMMENT=	Utility for mocking out the Python HTTPX library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.21.0:../../www/py-httpx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
