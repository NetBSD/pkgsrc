# $NetBSD: Makefile,v 1.35 2023/10/15 12:04:35 bsiegert Exp $
#
# Changelog:
# https://github.com/danielgtaylor/restish/releases/

DISTNAME=	restish-0.18.0
PKGREVISION=	3
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
