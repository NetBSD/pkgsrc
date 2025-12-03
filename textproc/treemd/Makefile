# $NetBSD: Makefile,v 1.7 2025/12/03 09:21:37 pin Exp $

DISTNAME=	treemd-0.4.2
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

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
