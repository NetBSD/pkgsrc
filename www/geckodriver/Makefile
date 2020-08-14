# $NetBSD: Makefile,v 1.14 2020/08/14 21:22:48 tnn Exp $

DISTNAME=	geckodriver-0.24.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_PROJECT=	geckodriver
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/geckodriver/
COMMENT=	W3C WebDriver-compatible proxy for Gecko-based browsers
LICENSE=	mpl-1.1

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

# Mozilla stopped providing a standalone Cargo.lock for geckodriver.
# So, we have to maintain a local copy.
post-extract:
	cp ${FILESDIR}/Cargo.lock ${WRKSRC}/Cargo.lock

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/geckodriver ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
