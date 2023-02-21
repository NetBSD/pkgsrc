# $NetBSD: Makefile,v 1.4 2023/02/21 13:30:55 pin Exp $

DISTNAME=	rusti-cal-1.1.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=arthurhenrique/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
