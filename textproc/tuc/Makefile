# $NetBSD: Makefile,v 1.1 2022/05/03 13:01:05 pin Exp $

DISTNAME=	tuc-0.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=riquito/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/riquito/tuc/
COMMENT=	When cut doesn't cut it
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tuc \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
