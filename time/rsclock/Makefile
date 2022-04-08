# $NetBSD: Makefile,v 1.1 2022/04/08 10:21:52 pin Exp $

DISTNAME=	v.0.1.7
PKGNAME=	rsclock-0.1.7
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=valebes/}
GITHUB_PROJECT=	rsClock
GITHUB_TAG=	v.0.1.7

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/valebes/rsClock/
COMMENT=	Simple terminal clock
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/rsClock-${DISTNAME}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rsclock \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
