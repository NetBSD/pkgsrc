# $NetBSD: Makefile,v 1.81 2025/08/31 10:03:03 bsiegert Exp $

DISTNAME=		pup-0.4.0
PKGREVISION=		75
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=ericchiang/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/ericchiang/pup/
COMMENT=		Parsing HTML at the command line
LICENSE=		mit

GO_BUILD_PATTERN=	.
INSTALLATION_DIRS+=	share/doc/pup

pre-patch:
	${CP} ${FILESDIR}/go.mod ${WRKSRC}
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/pup

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
