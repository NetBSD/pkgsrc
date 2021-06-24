# $NetBSD: Makefile,v 1.1 2021/06/24 10:37:30 pin Exp $

DISTNAME=	xurl-0.1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=squioc/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/squioc/xurl/
COMMENT=	Little tool to manipulate urls
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xurl ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
