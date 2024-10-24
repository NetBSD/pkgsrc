# $NetBSD: Makefile,v 1.8 2024/10/24 07:50:14 pin Exp $

DISTNAME=	zet-1.0.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=yarrow/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	b6a0c67f6ac76fb7bf8234951678b77fbac12d76

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
