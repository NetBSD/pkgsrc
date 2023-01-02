# $NetBSD: Makefile,v 1.7 2023/01/02 12:54:00 pin Exp $

DISTNAME=	tuc-0.11.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=riquito/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/riquito/tuc/
COMMENT=	When cut doesn't cut it
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tuc \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/tuc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tuc.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
