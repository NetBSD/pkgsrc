# $NetBSD: Makefile,v 1.14 2024/06/05 17:19:33 pin Exp $

DISTNAME=	wired-notify-0.10.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Toqozz/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Toqozz/wired-notify/
COMMENT=	Lightweight notification daemon with customizable layout blocks
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin share/examples/wired-notify

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/wired.ron \
		${DESTDIR}${PREFIX}/share/examples/wired-notify
	${INSTALL_DATA} ${WRKSRC}/wired_multilayout.ron \
		${DESTDIR}${PREFIX}/share/examples/wired-notify

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
