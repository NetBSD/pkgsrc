# $NetBSD: Makefile,v 1.14 2025/04/22 21:18:46 wiz Exp $

DISTNAME=	h11-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h11/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/h11
COMMENT=	Pure-Python, bring-your-own-I/O implementation of HTTP/1.1
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 0.14.0
# 1 failed, 77 passed
# with:
#ALLOW_NETWORK_ACCESS=	yes
# 78 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
