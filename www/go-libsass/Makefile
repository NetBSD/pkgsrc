# $NetBSD: Makefile,v 1.10 2019/10/18 14:59:00 bsiegert Exp $

DISTNAME=	go-libsass-0.9.2.0.20180625
MASTER_SITES=	${MASTER_SITE_GITHUB:=wellington/}
PKGREVISION=	9
CATEGORIES=	www
GITHUB_PROJECT=	go-libsass
GITHUB_TAG=	615eaa47ef794d037c1906a0eb7bf85375a5decf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wellington/go-libsass
COMMENT=	Go wrapper for libsass, the only Sass 3.5 compiler for Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${PKGBASE}-${GITHUB_TAG}
GO_SRCPATH=	github.com/wellington/go-libsass

USE_LANGUAGES=	c c++

.include "../../net/go-net/buildlink3.mk"
.include "../../www/go-spritewell/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
