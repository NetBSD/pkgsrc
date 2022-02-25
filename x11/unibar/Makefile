# $NetBSD: Makefile,v 1.5 2022/02/25 09:17:37 pin Exp $

DISTNAME=	unibar-0.1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ikubetoomuzik/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ikubetoomuzik/unibar/
COMMENT=	Simple status bar in rust
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/unibar ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
