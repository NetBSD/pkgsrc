# $NetBSD: Makefile,v 1.2 2022/03/29 10:39:07 pin Exp $

DISTNAME=	scatterbrainedsearch-2.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=m0lese/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/m0lese/scatterbrainedsearch/
COMMENT=	Scatterbrained implementation of minigrep
LICENSE=	apache-2.0 OR mit

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sbs \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
