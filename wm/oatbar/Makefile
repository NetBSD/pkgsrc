# $NetBSD: Makefile,v 1.6 2024/07/18 09:58:29 pin Exp $

DISTNAME=	oatbar-0.1.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=igor-petruk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://oatbar.app/
COMMENT=	Standalone desktop bar
LICENSE=	apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
.endif
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.cairo}/lib

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
.include "../../mk/bsd.pkg.mk"
