# $NetBSD: Makefile,v 1.73 2023/09/08 19:06:13 bsiegert Exp $

DISTNAME=	caddy-2.6.4
PKGREVISION=	6
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=caddyserver/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://caddyserver.com/
COMMENT=	General-purpose web server
LICENSE=	apache-2.0

EXTRACT_USING=		bsdtar

# Work around go's lack of conditional compilation.
pre-patch:
	${CP} ${WRKSRC}/listen_unix.go ${WRKSRC}/listen_illumos.go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
