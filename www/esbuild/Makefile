# $NetBSD: Makefile,v 1.26 2026/01/15 19:54:58 bsiegert Exp $

DISTNAME=	esbuild-0.25.9
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	6
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
