# $NetBSD: Makefile,v 1.7 2020/10/15 13:08:32 bsiegert Exp $

DISTNAME=		go-ffuf-1.1.0
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=ffuf/}
GITHUB_PROJECT=		ffuf
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ffuf/ffuf/
COMMENT=		Fast web fuzzer
LICENSE=		mit

GO_SRCPATH=		github.com/ffuf/ffuf
GO_DIST_BASE=		ffuf-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin share/doc/go-ffuf

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/ffuf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/go-ffuf

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
