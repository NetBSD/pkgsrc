# $NetBSD: Makefile,v 1.66 2026/11/28 09:24:11 wiz Exp $

DISTNAME=	rumdl-0.3.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rvben/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rvben/rumdl/
COMMENT=	Markdown Linter
LICENSE=	mit

RUST_REQ=	1.98
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
