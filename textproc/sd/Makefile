# $NetBSD: Makefile,v 1.2 2021/04/24 19:57:26 pin Exp $

DISTNAME=	sd-0.7.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=chmln/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chmln/sd/
COMMENT=	Intuitive find and replace CLI
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sd ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
