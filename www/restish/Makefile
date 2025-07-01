# $NetBSD: Makefile,v 1.52 2025/07/01 19:01:01 wiz Exp $
#
# Changelog:
# https://github.com/rest-sh/restish/releases/

DISTNAME=	restish-0.21.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rest-sh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rest.sh/
COMMENT=	CLI for interacting with REST-ish HTTP APIs
LICENSE=	mit

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
