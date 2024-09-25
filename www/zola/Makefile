# $NetBSD: Makefile,v 1.19 2024/09/25 10:54:10 pin Exp $

DISTNAME=	zola-0.19.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=getzola/}
GITHUB_PROJECT=	zola
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.getzola.org/
COMMENT=	Static website generator
LICENSE=	mit

TOOL_DEPENDS+=  cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
