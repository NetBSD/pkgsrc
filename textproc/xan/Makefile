# $NetBSD: Makefile,v 1.3 2025/09/22 13:12:58 pin Exp $

DISTNAME=	xan-0.53.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=medialab/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/medialab/xan/
COMMENT=	CSV handling tool
LICENSE=	unlicense

#RUST_REQ=	1.90.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.90.0 on amd64
USE_LANGUAGES=	c
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/doc/xan

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/xan
	cd ${WRKSRC}/docs && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/doc/xan

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
