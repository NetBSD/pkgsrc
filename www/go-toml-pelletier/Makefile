# $NetBSD: Makefile,v 1.3 2017/08/25 16:49:15 jperkin Exp $

DISTNAME=	go-toml-1.0.0
PKGNAME=	${DISTNAME:S/toml/toml-pelletier/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=pelletier/}
CATEGORIES=	www
GITHUB_PROJECT=	go-toml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pelletier/go-toml
COMMENT=	TOML parser for Golang with reflection.
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/pelletier/go-toml

.include "../../devel/go-buffruneio/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
