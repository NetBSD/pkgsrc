# $NetBSD: Makefile,v 1.40 2021/09/17 13:52:51 bsiegert Exp $

DISTNAME=		pup-0.4.0
PKGREVISION=		35
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=ericchiang/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ericchiang/pup/
COMMENT=		Parsing HTML at the command line
LICENSE=		mit

GO_BUILD_PATTERN=	.

INSTALLATION_DIRS+=	bin share/doc/pup

pre-patch:
	${CP} ${FILESDIR}/go.mod ${WRKSRC}
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/pup ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/pup

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
