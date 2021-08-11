# $NetBSD: Makefile,v 1.41 2021/08/11 19:35:08 bsiegert Exp $

DISTNAME=	caddy-2.4.3
PKGREVISION=	2
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=caddyserver/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://caddyserver.com/
COMMENT=	General-purpose web server
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./...

CHECK_RELRO_SKIP+=	bin/caddy

EXTRACT_USING=		bsdtar

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/caddy ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
