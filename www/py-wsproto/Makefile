# $NetBSD: Makefile,v 1.4 2019/05/31 20:57:05 adam Exp $

DISTNAME=	wsproto-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wsproto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wsproto.readthedocs.io/
COMMENT=	Pure Python, pure state-machine WebSocket implementation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h11>=0.7.0:../../www/py-h11
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.0.4:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
