# $NetBSD: Makefile,v 1.2 2025/01/09 16:42:28 pin Exp $

DISTNAME=	clock-rs-0.1.213
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=Oughie/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Oughie/clock-rs/
COMMENT=	Modern, terminal-based digital clock
LICENSE=	apache-2.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
