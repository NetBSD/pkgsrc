# $NetBSD: Makefile,v 1.11 2022/02/06 07:53:10 adam Exp $

DISTNAME=	respx-0.19.2
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
