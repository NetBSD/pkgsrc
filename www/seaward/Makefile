# $NetBSD: Makefile,v 1.4 2024/02/23 17:25:27 pin Exp $

DISTNAME=	seaward-1.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=M3nny/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/M3nny/seaward/
COMMENT=	Crawler which searches for links or a specified word in a website
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
