# $NetBSD: Makefile,v 1.2 2026/05/25 14:02:59 wiz Exp $

DISTNAME=	xleak-0.2.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgreenwell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bgreenwell/xleak/
COMMENT=	Fast terminal Excel viewer with an interactive TUI
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
