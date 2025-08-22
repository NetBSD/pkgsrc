# $NetBSD: Makefile,v 1.5 2025/08/22 13:02:43 pin Exp $

DISTNAME=	clock-rs-0.1.216
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
