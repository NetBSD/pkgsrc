# $NetBSD: Makefile,v 1.1 2020/11/23 09:17:36 pin Exp $

DISTNAME=	zoxide-0.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ajeetdsouza/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/ajeetdsouza/zoxide/
COMMENT=	Faster way to navigate your filesystem
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin share/doc/zoxide

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zoxide ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/zoxide

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
