# $NetBSD: Makefile,v 1.20 2026/06/28 11:04:21 drixter Exp $

DISTNAME=	miniflux-2.3.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=miniflux/}
GITHUB_PROJECT=	v2
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
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
