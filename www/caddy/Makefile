# $NetBSD: Makefile,v 1.61 2022/11/02 19:39:50 bsiegert Exp $

DISTNAME=	caddy-2.6.2
PKGREVISION=	1
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=caddyserver/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://caddyserver.com/
COMMENT=	General-purpose web server
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./...
EXTRACT_USING=		bsdtar

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
