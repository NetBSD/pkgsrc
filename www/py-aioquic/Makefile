# $NetBSD: Makefile,v 1.7 2025/10/20 09:16:37 adam Exp $

DISTNAME=	aioquic-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioquic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aiortc/aioquic
COMMENT=	Fork of aioquic with adjustments for mitmproxy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=24:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=42.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-pylsqpack>=0.3.3:../../www/py-pylsqpack
DEPENDS+=	${PYPKGPREFIX}-service_identity>=24.1.0:../../security/py-service_identity

.include "../../lang/python/wheel.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
