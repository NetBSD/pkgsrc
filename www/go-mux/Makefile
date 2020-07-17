# $NetBSD: Makefile,v 1.9 2020/07/17 18:04:32 bsiegert Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-mux-1.7.3
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=gorilla/}
GITHUB_PROJECT=		mux

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://github.com/gorilla/mux
COMMENT=		URL router and dispatcher for Go
LICENSE=		modified-bsd # bsd-3

GO_SRCPATH=		github.com/gorilla/mux
GO_DIST_BASE=		mux-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
