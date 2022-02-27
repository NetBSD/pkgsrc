# $NetBSD: Makefile,v 1.1 2022/02/27 21:07:55 pin Exp $

DISTNAME=	scatterbrainedsearch-2.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=m0lese/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/m0lese/scatterbrainedsearch/
COMMENT=	Scatterbrained implementation of minigrep
LICENSE=	apache-2.0 OR mit

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sbs \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
