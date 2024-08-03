# $NetBSD: Makefile,v 1.1 2024/08/03 10:45:18 pin Exp $

DISTNAME=	reader-0.4.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrusme/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/mrusme/reader/
COMMENT=	Lightweight tool offering better readability of web pages on the CLI
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin share/doc/reader

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/reader \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/reader

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
