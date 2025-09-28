# $NetBSD: Makefile,v 1.2 2025/09/28 19:54:24 wiz Exp $

DISTNAME=	openapi_pydantic-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-pydantic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mike-oakley/openapi-pydantic
COMMENT=	Pydantic OpenAPI schema implementation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pydantic-[0-9]*:../../devel/py-pydantic

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
