# $NetBSD: Makefile,v 1.15 2025/03/07 20:54:32 bsiegert Exp $

DISTNAME=	esbuild-0.24.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=evanw/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://esbuild.github.io/
COMMENT=	Fast JavaScript bundler and minifier
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
