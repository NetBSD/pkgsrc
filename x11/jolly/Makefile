# $NetBSD: Makefile,v 1.7 2023/11/12 13:24:09 wiz Exp $

DISTNAME=	jolly-0.3.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=apgoetz/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/apgoetz/jolly/
COMMENT=	Small bookmarking launcher for desktop usage
LICENSE=	mit OR apache-2.0

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/examples/jolly share/icons/hicolor/scalable/apps

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jolly \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/jolly.toml \
		${DESTDIR}${PREFIX}/share/examples/jolly
	${INSTALL_DATA} ${WRKSRC}/icon/jolly.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
