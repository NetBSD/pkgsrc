# $NetBSD: Makefile,v 1.11 2022/01/04 20:55:29 wiz Exp $

DISTNAME=	h2-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/h2
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hyperframe>=6.0.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=4.0:../../net/py-hpack
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
