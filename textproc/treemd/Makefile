# $NetBSD: Makefile,v 1.3 2025/11/16 16:59:13 pin Exp $

DISTNAME=	treemd-0.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Epistates/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Epistates/treemd/
COMMENT=	TUI/CLI markdown navigator with tree-based structural navigation
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.85.0
USE_TOOLS+=	pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
