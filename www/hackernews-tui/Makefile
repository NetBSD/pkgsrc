# $NetBSD: Makefile,v 1.5 2021/04/25 19:56:23 pin Exp $

DISTNAME=	hackernews-TUI-0.5.1
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
USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hackernews_tui ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
