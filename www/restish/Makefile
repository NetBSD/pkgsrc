# $NetBSD: Makefile,v 1.5 2022/01/23 22:25:15 wiz Exp $

DISTNAME=	restish-0.9.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=danielgtaylor/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rest.sh/
COMMENT=	CLI for interacting with REST-ish HTTP APIs
LICENSE=	mit

USE_LANGUAGES=	# none

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
