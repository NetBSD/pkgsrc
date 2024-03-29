# $NetBSD: Makefile,v 1.7 2023/10/23 06:37:59 wiz Exp $

DISTNAME=	xcolor-0.5.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Soft/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Soft/xcolor/
COMMENT=	Lightweight color picker for X11
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xcolor ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/xcolor.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xcolor.1

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
