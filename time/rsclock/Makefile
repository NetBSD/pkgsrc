# $NetBSD: Makefile,v 1.2 2023/10/10 12:11:15 pin Exp $

DISTNAME=	rsclock-0.1.10
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
