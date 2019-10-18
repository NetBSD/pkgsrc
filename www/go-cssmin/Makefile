# $NetBSD: Makefile,v 1.15 2019/10/18 14:58:59 bsiegert Exp $

DISTNAME=	cssmin-0.0.20151210
PKGNAME=	go-${DISTNAME}
PKGREVISION=	13
MASTER_SITES=	${MASTER_SITE_GITHUB:=dchest/}
CATEGORIES=	www
GITHUB_TAG=	fb8d9b44afdc258bfff6052d3667521babcb2239
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dchest/cssmin
COMMENT=	Go port of Ryan Grove's cssmin
LICENSE=	modified-bsd

GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/dchest/cssmin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
