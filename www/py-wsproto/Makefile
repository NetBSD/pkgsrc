# $NetBSD: Makefile,v 1.8 2022/11/27 09:55:37 adam Exp $

DISTNAME=	wsproto-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wsproto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wsproto.readthedocs.io/
COMMENT=	Pure Python, pure state-machine WebSocket implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h11>=0.9.0:../../www/py-h11
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
