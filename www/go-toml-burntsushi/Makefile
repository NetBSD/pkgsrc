# $NetBSD: Makefile,v 1.22 2020/03/21 16:57:02 bsiegert Exp $

DISTNAME=	toml-0.3.1
PKGNAME=	go-${DISTNAME:S/toml/toml-burntsushi/}
PKGREVISION=	13
MASTER_SITES=	${MASTER_SITE_GITHUB:=BurntSushi/}
CATEGORIES=	www
GITHUB_PROJECT=	toml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BurntSushi/toml
COMMENT=	TOML parser for Golang with reflection
# LICENSE=	wtfpl

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/BurntSushi/toml

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
