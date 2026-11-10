# $NetBSD: Makefile,v 1.36 2026/11/10 18:55:31 bsiegert Exp $

DISTNAME=	mycorrhiza-1.14.0
PKGREVISION=	35
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=bouncepaw/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mycorrhiza.wiki/
COMMENT=	Filesystem and git-based wiki engine
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
