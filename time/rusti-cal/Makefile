# $NetBSD: Makefile,v 1.1 2022/09/10 16:16:27 pin Exp $

DISTNAME=	rusti-cal-0.4.5
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
