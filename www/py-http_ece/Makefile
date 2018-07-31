# $NetBSD: Makefile,v 1.1 2018/07/31 16:44:21 nia Exp $

DISTNAME=	http_ece-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/http-ece/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/web-push-libs/encrypted-content-encoding
COMMENT=	Python support for the encryped Content-Encoding (RFC 8188)
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
