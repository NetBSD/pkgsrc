# $NetBSD: Makefile,v 1.16 2025/05/30 21:36:26 tnn Exp $

DISTNAME=	geckodriver-0.36.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_PROJECT=	geckodriver
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/geckodriver/
COMMENT=	W3C WebDriver-compatible proxy for Gecko-based browsers
LICENSE=	mpl-1.1

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/geckodriver ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
