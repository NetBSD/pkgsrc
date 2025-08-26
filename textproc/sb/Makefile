# $NetBSD: Makefile,v 1.2 2025/08/26 13:22:46 pin Exp $

DISTNAME=	sb-0.3.12
CATEGORIES=	textproc
#MASTER_SITES=	${MASTER_SITE_GITHUB:=dirvine/}
MASTER_SITES=	https://static.crates.io/crates/sb/
#GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dirvine/sb/
COMMENT=	Terminal Markdown Browser/Editor with Vim-like features
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "../../lang/rust/cargo.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
