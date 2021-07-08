# $NetBSD: Makefile,v 1.3 2021/07/08 13:33:26 pin Exp $

DISTNAME=	unibar-0.1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ikubetoomuzik/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ikubetoomuzik/unibar/
COMMENT=	Simple status bar in rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c # rust, but needs a toolchain to link
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/unibar ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
