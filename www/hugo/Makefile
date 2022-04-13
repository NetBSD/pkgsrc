# $NetBSD: Makefile,v 1.58 2022/04/13 07:50:56 bsiegert Exp $

DISTNAME=	hugo-0.96.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=gohugoio/}
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gohugo.io/
COMMENT=	Fast & Modern Static Website Engine
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	-tags "extended"
GO_VERSION_DEFAULT=	118

MAKE_ENV+=	"CGO_ENABLED=1"
MAKE_ENV+=	"CGO_LDFLAGS=-lm"
USE_LANGUAGES+=	c c++
LIBS+=		-lm

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
