# $NetBSD: Makefile,v 1.17 2026/10/24 17:21:09 pin Exp $

DISTNAME=	monolith-2.11.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Y2Z/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Y2Z/monolith/
COMMENT=	CLI tool for saving complete web pages as a single HTML file
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

# aws-lc-sys builds jitterentropy with -O0 flag.
# Forcing the -O2 flag triggers a build error.
# Disable the jitterentropy build.
MAKE_ENV+=	AWS_LC_SYS_NO_JITTER_ENTROPY=1

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
