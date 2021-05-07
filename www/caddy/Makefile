# $NetBSD: Makefile,v 1.35 2021/05/07 15:50:51 bsiegert Exp $

DISTNAME=	caddy-2.3.0
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
