# $NetBSD: Makefile,v 1.33 2026/05/07 18:50:10 bsiegert Exp $

DISTNAME=	esbuild-0.28.0
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
