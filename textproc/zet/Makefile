# $NetBSD: Makefile,v 1.9 2025/10/21 09:07:33 wiz Exp $

DISTNAME=	zet-2.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=yarrow/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yarrow/zet/
COMMENT=	CLI utility to find the union, intersection, etc of files
LICENSE=	apache-2.0 OR mit

# https://github.com/yarrow/zet/issues/12
BROKEN=		"Does not build with rust 1.90"

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zet \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
