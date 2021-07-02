# $NetBSD: Makefile,v 1.1 2021/07/02 21:59:54 pin Exp $

DISTNAME=	xsv-0.13.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BurntSushi/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/BurntSushi/xsv/
COMMENT=	Fast CSV command line toolkit written in Rust
LICENSE=	unlicense AND mit

USE_LANGUAGES=	c

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xsv ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
