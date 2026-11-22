# $NetBSD: Makefile,v 1.33 2026/11/22 17:40:22 wiz Exp $

DISTNAME=	reader-0.6.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrusme/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrusme/reader/
COMMENT=	Lightweight tool offering better readability of web pages on the CLI
LICENSE=	segv-1.1-license

RESTRICTED=		Field of use restrictions and Duty of Care
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

INSTALLATION_DIRS=	bin share/doc/reader

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/reader \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/reader

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
