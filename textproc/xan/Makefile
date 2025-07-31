# $NetBSD: Makefile,v 1.2 2025/07/31 11:49:48 pin Exp $

DISTNAME=	xan-0.52.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=medialab/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/medialab/xan/
COMMENT=	CSV handling tool
LICENSE=	unlicense

#RUST_REQ=		1.88.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.88.0 on amd64
USE_LANGUAGES=	c
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/doc/xan

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/xan
	cd ${WRKSRC}/docs && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/doc/xan

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
