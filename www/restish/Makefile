# $NetBSD: Makefile,v 1.64 2026/05/07 18:50:11 bsiegert Exp $
#
# Changelog:
# https://github.com/rest-sh/restish/releases/

DISTNAME=	restish-0.21.2
PKGREVISION=	5
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
