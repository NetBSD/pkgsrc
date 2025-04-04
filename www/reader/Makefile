# $NetBSD: Makefile,v 1.7 2025/04/04 20:03:41 pin Exp $

DISTNAME=	reader-0.4.7
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrusme/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
