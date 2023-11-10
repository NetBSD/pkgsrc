# $NetBSD: Makefile,v 1.5 2023/11/10 15:45:24 bsiegert Exp $

DISTNAME=	mycorrhiza-1.14.0
PKGREVISION=	4
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
