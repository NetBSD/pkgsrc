# $NetBSD: Makefile,v 1.15 2025/04/27 06:20:39 wiz Exp $

DISTNAME=	h11-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h11/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/h11
COMMENT=	Pure-Python, bring-your-own-I/O implementation of HTTP/1.1
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

# for testing
ALLOW_NETWORK_ACCESS=	yes
# as of 0.16.0
# 78 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
