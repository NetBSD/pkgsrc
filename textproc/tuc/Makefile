# $NetBSD: Makefile,v 1.9 2023/02/28 22:38:42 pin Exp $

DISTNAME=	tuc-1.0.0
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
