# $NetBSD: Makefile,v 1.4 2023/01/02 12:50:20 pin Exp $

DISTNAME=	prose-0.4.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgdavey/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgdavey/prose/
COMMENT=	Reformat text pleasantly
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/prose \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
