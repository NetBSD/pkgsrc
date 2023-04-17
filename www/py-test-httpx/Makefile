# $NetBSD: Makefile,v 1.3 2023/04/17 09:59:50 adam Exp $

DISTNAME=	pytest_httpx-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-httpx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://colin-b.github.io/pytest_httpx/
COMMENT=	Send responses to httpx
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.24:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-test>=6.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
