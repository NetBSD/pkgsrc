# $NetBSD: Makefile,v 1.6 2022/06/07 10:14:21 pin Exp $

DISTNAME=	heliocron-0.6.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=mfreeborn/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	37909ef696cf0b1e429817127375d66b314bc159

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mfreeborn/heliocron/
COMMENT=	Execute tasks relative to sunset, sunrise and other solar events
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/heliocron \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
