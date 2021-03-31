# $NetBSD: Makefile,v 1.1 2021/03/31 20:26:41 pin Exp $

DISTNAME=	quest-tui-0.2.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=frustak/}
GITHUB_PROJECT=	Quest
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/frustak/Quest/
COMMENT=	Rust todo TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/quest-tui ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
