# $NetBSD: Makefile,v 1.6 2022/10/14 08:29:37 adam Exp $

DISTNAME=	sanic-routing-22.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sanic-routing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sanic-org/sanic-routing
COMMENT=	Core routing component for Sanic
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
