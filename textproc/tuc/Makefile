# $NetBSD: Makefile,v 1.12 2025/04/04 20:23:37 pin Exp $

DISTNAME=	tuc-1.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=riquito/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/riquito/tuc/
COMMENT=	When cut doesn't cut it
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/tuc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tuc.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
