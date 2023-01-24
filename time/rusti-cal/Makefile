# $NetBSD: Makefile,v 1.3 2023/01/24 13:21:24 pin Exp $

DISTNAME=	rusti-cal-1.1.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=arthurhenrique/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/arthurhenrique/rusti-cal/
COMMENT=	Minimal calendar command line
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rusti-cal \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
