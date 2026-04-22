# $NetBSD: Makefile,v 1.140.2.1 2026/04/22 14:32:20 maya Exp $

DISTNAME=	hugo-0.157.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_GITHUB:=gohugoio/}
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gohugo.io/
COMMENT=	Fast & Modern Static Website Engine
LICENSE=	apache-2.0

GOFLAGS=		-tags "extended"
GO_BUILD_PATTERN=	.

MAKE_ENV+=	"CGO_ENABLED=1"
MAKE_ENV+=	"CGO_LDFLAGS=-lm"
USE_LANGUAGES+=	c c++
LIBS+=		-lm

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
