# $NetBSD: Makefile,v 1.1 2021/06/15 07:27:30 pin Exp $

DISTNAME=	zet-0.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=yarrow/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/yarrow/zet/
COMMENT=	CLI utility to find the union, intersection, etc of files
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zet ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
