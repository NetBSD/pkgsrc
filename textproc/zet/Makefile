# $NetBSD: Makefile,v 1.6 2023/02/03 21:34:28 pin Exp $

DISTNAME=	zet-0.2.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=yarrow/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yarrow/zet/
COMMENT=	CLI utility to find the union, intersection, etc of files
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zet \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
