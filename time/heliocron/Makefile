# $NetBSD: Makefile,v 1.2 2021/04/24 19:46:03 pin Exp $

DISTNAME=	heliocron-0.5.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=mfreeborn/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mfreeborn/heliocron/
COMMENT=	Execute tasks relative to sunset, sunrise and other solar events
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES+=	c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/heliocron ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
