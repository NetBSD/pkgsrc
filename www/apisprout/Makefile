# $NetBSD: Makefile,v 1.56 2026/10/13 18:38:01 bsiegert Exp $

DISTNAME=	apisprout-1.3.0
PKGREVISION=	54
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=danielgtaylor/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/danielgtaylor/apisprout/
COMMENT=	Lightweight, fast, validating OpenAPI 3 mock server
LICENSE=	mit

USE_LANGUAGES=	c

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
