# $NetBSD: Makefile,v 1.6 2023/11/08 06:56:54 pin Exp $

DISTNAME=	sd-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=chmln/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/chmln/sd/
COMMENT=	Intuitive find and replace CLI
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/gen/sd.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sd.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
