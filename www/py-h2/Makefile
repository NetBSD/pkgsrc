# $NetBSD: Makefile,v 1.14 2025/08/24 16:08:36 wiz Exp $

DISTNAME=	h2-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/h2
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-hyperframe>=6.0.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=4.0:../../net/py-hpack
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
