# $NetBSD: Makefile,v 1.14 2024/01/26 13:51:23 adam Exp $

DISTNAME=	PasteDeploy-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PasteDeploy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Pylons/pastedeploy/
COMMENT=	Load, configure, and compose WSGI applications and servers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=41:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
