# $NetBSD: Makefile,v 1.50 2021/11/05 20:02:50 bsiegert Exp $

DISTNAME=	hugo-0.87.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	3
MASTER_SITES=	${MASTER_SITE_GITHUB:=gohugoio/}
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gohugo.io/
COMMENT=	Fast & Modern Static Website Engine
LICENSE=	apache-2.0

GO_BUILD_PATTERN=

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
