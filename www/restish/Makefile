# $NetBSD: Makefile,v 1.50 2025/04/05 18:51:31 bsiegert Exp $
#
# Changelog:
# https://github.com/danielgtaylor/restish/releases/

DISTNAME=	restish-0.20.0
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=danielgtaylor/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rest.sh/
COMMENT=	CLI for interacting with REST-ish HTTP APIs
LICENSE=	mit

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
