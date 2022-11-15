# $NetBSD: Makefile,v 1.1 2022/11/15 12:17:08 adam Exp $

DISTNAME=	pytest_httpx-0.21.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-httpx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://colin-b.github.io/pytest_httpx/
COMMENT=	Send responses to httpx
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.23.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-test>=6.0.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
