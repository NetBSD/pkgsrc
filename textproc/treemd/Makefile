# $NetBSD: Makefile,v 1.28 2026/09/16 13:11:05 pin Exp $

DISTNAME=	treemd-0.9.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Epistates/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Epistates/treemd/
COMMENT=	TUI/CLI markdown navigator with tree-based structural navigation
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.90.0
USE_TOOLS+=	pkg-config

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
