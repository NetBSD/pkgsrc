# $NetBSD: Makefile,v 1.2 2024/02/19 18:29:12 adam Exp $

DISTNAME=	aioquic-0.9.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioquic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aiortc/aioquic
COMMENT=	Fork of aioquic with adjustments for mitmproxy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-pylsqpack>=0.3.3:../../www/py-pylsqpack
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=22:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-service_identity>=23.1.0:../../security/py-service_identity

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
