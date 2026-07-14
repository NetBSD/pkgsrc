# $NetBSD: Makefile,v 1.12 2026/07/14 11:21:17 pin Exp $

DISTNAME=	xan-0.60.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=medialab/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/medialab/xan/
COMMENT=	CSV handling tool
LICENSE=	unlicense

RUST_REQ=	1.85.0
USE_LANGUAGES=	c
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/doc/xan

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/xan
	cd ${WRKSRC}/docs && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/doc/xan

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
