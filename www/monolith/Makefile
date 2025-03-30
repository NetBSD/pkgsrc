# $NetBSD: Makefile,v 1.15 2025/03/30 16:52:07 pin Exp $

DISTNAME=	monolith-2.10.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Y2Z/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Y2Z/monolith/
COMMENT=	CLI tool for saving complete web pages as a single HTML file
LICENSE=	cc0-1.0-universal

SITES.wasi-0.11.0+wasi-snapshop-preview1.crate=	https://static.crates.io/crates/wasi/
SITES.wasi-0.14.2+wasi-0.2.4.crate=		https://static.crates.io/crates/wasi/

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
