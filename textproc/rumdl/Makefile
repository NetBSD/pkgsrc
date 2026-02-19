# $NetBSD: Makefile,v 1.12 2026/02/19 08:19:55 pin Exp $

DISTNAME=	rumdl-0.1.23
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
