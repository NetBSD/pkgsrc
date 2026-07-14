# $NetBSD: Makefile,v 1.33.2.1 2026/07/14 00:36:11 maya Exp $

DISTNAME=	shoutrrr-0.8.0
PKGREVISION=	29
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
