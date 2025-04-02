# $NetBSD: Makefile,v 1.6 2025/04/02 18:01:59 pin Exp $

DISTNAME=	lefthk-0.2.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=leftwm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leftwm/lefthk/
COMMENT=	Hotkey daemon written in Rust
LICENSE=	modified-bsd

CONFLICTS=	leftwm-[0-9]*

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/lefthk \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
