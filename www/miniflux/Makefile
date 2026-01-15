# $NetBSD: Makefile,v 1.9 2026/01/15 19:54:59 bsiegert Exp $

DISTNAME=	miniflux-2.2.16
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=miniflux/}
GITHUB_PROJECT=	v2
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miniflux/v2/
COMMENT=	Minimalist and opinionated feed reader
LICENSE=	apache-2.0

USE_LANGUAGES=	c

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/miniflux.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
