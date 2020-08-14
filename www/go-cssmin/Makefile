# $NetBSD: Makefile,v 1.24 2020/08/14 20:01:20 bsiegert Exp $

DISTNAME=	cssmin-0.0.20151210
PKGNAME=	go-${DISTNAME}
PKGREVISION=	21
MASTER_SITES=	${MASTER_SITE_GITHUB:=dchest/}
CATEGORIES=	www
GITHUB_TAG=	fb8d9b44afdc258bfff6052d3667521babcb2239
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dchest/cssmin
COMMENT=	Go port of Ryan Grove's cssmin
LICENSE=	modified-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/dchest/cssmin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
