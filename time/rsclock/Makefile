# $NetBSD: Makefile,v 1.3 2024/01/13 19:26:12 pin Exp $

DISTNAME=	rsclock-0.1.11
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
