# $NetBSD: Makefile,v 1.20 2022/10/09 16:05:31 pin Exp $

DISTNAME=	hackernews-TUI-0.11.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=aome510/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/aome510/hackernews-TUI/
COMMENT=	Terminal UI to browse Hacker News
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS=	bin share/examples/hackernews-tui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hackernews_tui \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/hn-tui.toml \
		${DESTDIR}${PREFIX}/share/examples/hackernews-tui

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
