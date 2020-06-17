# $NetBSD: Makefile,v 1.16 2020/06/17 09:54:20 bsiegert Exp $

DISTNAME=	go-tocss-0.5.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=bep/}
PKGREVISION=	15
CATEGORIES=	www
GITHUB_PROJECT=	go-tocss
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bep/go-tocss
COMMENT=	Simple to use Go API for LibSass. Uses CGO
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/bep/go-tocss

USE_LANGUAGES=	c c++

.include "../../www/go-libsass/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
