# $NetBSD: Makefile,v 1.3 2022/02/25 09:16:48 pin Exp $

DISTNAME=	stava-0.6.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=simeg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simeg/stava/
COMMENT=	CLI spell checker
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stava ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
