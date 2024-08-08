# $NetBSD: Makefile,v 1.6 2024/08/08 17:29:34 pin Exp $

DISTNAME=	cobalt-0.19.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cobalt-org/}
GITHUB_PROJECT=	cobalt.rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cobalt-org/cobalt.rs/
COMMENT=	Static website generator
LICENSE=	mit

RUST_REQ=	1.76.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

# Switch off sass feature by default due to libsass and sass-rs deprecation
# See, https://github.com/cobalt-org/cobalt.rs/issues/1050
# and https://github.com/cobalt-org/cobalt.rs/pull/1090
CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		syntax-highlight serve html-minifier

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
