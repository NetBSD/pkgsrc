# $NetBSD: Makefile,v 1.28 2026/01/15 19:55:00 bsiegert Exp $

DISTNAME=	shoutrrr-0.8.0
PKGREVISION=	23
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=containrrr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://containrrr.dev/shoutrrr/
COMMENT=	Notification library and CLI for gophers and their furry friends
LICENSE=	mit

GO_BUILD_PATTERN+=	./shoutrrr

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
