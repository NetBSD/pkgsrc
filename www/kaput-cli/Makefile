# $NetBSD: Makefile,v 1.1 2024/01/16 17:10:08 nikita Exp $

DISTNAME=	kaput-cli-2.1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=davidchalifoux/}
GITHUB_PROJECT=	kaput-cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidchalifoux/kaput-cli
COMMENT=	Command-line tool for put.io
LICENSE=	mit

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl:build gmake

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
