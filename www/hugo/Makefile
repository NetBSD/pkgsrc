# $NetBSD: Makefile,v 1.40 2021/03/19 17:37:10 bsiegert Exp $

DISTNAME=	hugo-0.80.0
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

GO_BUILD_PATTERN=

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
