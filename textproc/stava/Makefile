# $NetBSD: Makefile,v 1.2 2021/08/03 09:02:05 pin Exp $

DISTNAME=	stava-0.6.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=simeg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/simeg/stava/
COMMENT=	CLI spell checker
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stava ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
