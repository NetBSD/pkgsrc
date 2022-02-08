# $NetBSD: Makefile,v 1.3 2022/02/08 12:40:34 pin Exp $

DISTNAME=	wired-notify-0.10.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Toqozz/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Toqozz/wired-notify/
COMMENT=	Lightweight notification daemon with customizable layout blocks
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wired ${DESTDIR}${PREFIX}/bin


.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
