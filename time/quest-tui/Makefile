# $NetBSD: Makefile,v 1.3 2022/03/29 10:14:47 pin Exp $

DISTNAME=	quest-tui-0.2.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=frustak/}
GITHUB_PROJECT=	Quest
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frustak/Quest/
COMMENT=	Rust todo TUI
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/quest-tui \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
