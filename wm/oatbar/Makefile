# $NetBSD: Makefile,v 1.12 2026/04/16 07:56:20 pin Exp $

DISTNAME=	oatbar-0.3.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=igor-petruk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oatbar.app/
COMMENT=	Standalone desktop bar
LICENSE=	apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=	1.95.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.95.0 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
.endif
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cairo}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
