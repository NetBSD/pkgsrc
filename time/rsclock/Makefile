# $NetBSD: Makefile,v 1.4 2025/03/30 16:55:10 pin Exp $

DISTNAME=	rsclock-0.1.12
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=valebes/}
GITHUB_PROJECT=	rsClock
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/valebes/rsClock/
COMMENT=	Simple terminal clock
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
