# $NetBSD: Makefile,v 1.11 2024/01/02 16:02:44 pin Exp $

DISTNAME=	tuc-1.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=riquito/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
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
