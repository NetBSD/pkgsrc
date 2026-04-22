# $NetBSD: Makefile,v 1.29.2.1 2026/04/22 14:32:19 maya Exp $

DISTNAME=	esbuild-0.27.3
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	2
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
