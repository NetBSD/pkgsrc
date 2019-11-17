# $NetBSD: Makefile,v 1.9.2.1 2019/11/17 08:30:21 spz Exp $

DISTNAME=	spritewell-0.5.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	9
MASTER_SITES=	${MASTER_SITE_GITHUB:=wellington/}
CATEGORIES=	www
GITHUB_PROJECT=	spritewell
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wellington/spritewell
COMMENT=	Native go implementation of image composition for CSS spriting

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/wellington/spritewell

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
