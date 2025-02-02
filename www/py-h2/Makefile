# $NetBSD: Makefile,v 1.12 2025/02/02 16:04:23 wiz Exp $

DISTNAME=	h2-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/h2
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-hyperframe>=6.0.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=4.0:../../net/py-hpack
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
