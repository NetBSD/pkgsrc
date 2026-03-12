# $NetBSD: Makefile,v 1.19 2026/03/12 17:19:30 pin Exp $

DISTNAME=	rumdl-0.1.42
# rumdl >= v0.1.43 requires Rust >= 1.94
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rvben/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rvben/rumdl/
COMMENT=	Markdown Linter
LICENSE=	mit

RUST_REQ=	1.91.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
