# $NetBSD: Makefile,v 1.9 2025/10/01 09:32:34 pin Exp $

DISTNAME=	cobalt-0.20.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cobalt-org/}
GITHUB_PROJECT=	cobalt.rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cobalt-org/cobalt.rs/
COMMENT=	Static website generator
LICENSE=	mit

RUST_REQ=	1.85.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
