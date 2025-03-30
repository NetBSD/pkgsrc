# $NetBSD: Makefile,v 1.1 2025/03/30 07:54:27 wiz Exp $

DISTNAME=	presenterm-0.12.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mfontanini/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mfontanini.github.io/presenterm/
COMMENT=	Markdown terminal slideshow tool
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c
# for sixel-sys crate
USE_TOOLS+=		gmake
CARGO_FEATURES+=	sixel

# ensure libsixel is available to the rust compiler
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libsixel}/lib

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../graphics/libsixel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
