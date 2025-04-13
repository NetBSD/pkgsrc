# $NetBSD: Makefile,v 1.13 2025/04/13 16:10:24 wiz Exp $

DISTNAME=	h2-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
