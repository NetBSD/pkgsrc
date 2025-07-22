# $NetBSD: Makefile,v 1.7 2025/07/22 13:30:25 pin Exp $

DISTNAME=	lefthk-0.3.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=leftwm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/leftwm/lefthk/
COMMENT=	Hotkey daemon written in Rust
LICENSE=	modified-bsd

CONFLICTS=	leftwm-[0-9]*

.include "cargo-depends.mk"

RUST_REQ=		1.85.0
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lefthk \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
