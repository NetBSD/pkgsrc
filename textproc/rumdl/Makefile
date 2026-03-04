# $NetBSD: Makefile,v 1.16 2026/03/04 14:55:53 pin Exp $

DISTNAME=	rumdl-0.1.38
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
