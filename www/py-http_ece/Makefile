# $NetBSD: Makefile,v 1.4 2024/05/05 20:03:56 wiz Exp $

DISTNAME=	http_ece-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/http-ece/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/web-push-libs/encrypted-content-encoding
COMMENT=	Python support for the encryped Content-Encoding (RFC 8188)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

.include "../../lang/python/wheel.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
