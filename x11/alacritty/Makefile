# $NetBSD: Makefile,v 1.8 2021/07/12 14:10:10 tnn Exp $

DISTNAME=	alacritty-0.8.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=alacritty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alacritty/alacritty
COMMENT=	Cross-platform, GPU-accelerated terminal emulator
LICENSE=	apache-2.0

BUILD_DEPENDS+=		cmake-[0-9]*:../../devel/cmake
BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config	# for fontconfig-sys

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${X11_TYPE} == "native"
# This works around XIM errors when RTLD local-binding libX11.
# See: https://mail-index.netbsd.org/tech-x11/2021/07/12/msg002222.html
# But it might also break GPU accelerated mode.
SUBST_CLASSES+=		rtld
SUBST_MESSAGE.rtld=	amend RTLD_GLOBAL
SUBST_STAGE.rtld=	pre-configure
SUBST_FILES.rtld=	../vendor/x11-dl-2.18.5/src/link.rs
SUBST_SED.rtld=		-e 's,libc::RTLD_LAZY,& | libc::RTLD_GLOBAL,g'
.endif

# The xcb crate depends on any version of python 3.
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin share/examples/alacritty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/alacritty ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/alacritty.yml ${DESTDIR}${PREFIX}/share/examples/alacritty

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
