# $NetBSD: Makefile,v 1.3 2024/06/27 11:34:41 adam Exp $

DISTNAME=	aioquic-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioquic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aiortc/aioquic
COMMENT=	Fork of aioquic with adjustments for mitmproxy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=22:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=42.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-pylsqpack>=0.3.3:../../www/py-pylsqpack
DEPENDS+=	${PYPKGPREFIX}-service_identity>=24.1.0:../../security/py-service_identity

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
