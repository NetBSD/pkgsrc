# $NetBSD: Makefile,v 1.64 2023/01/11 17:28:37 bsiegert Exp $

DISTNAME=	caddy-2.6.2
PKGREVISION=	3
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

post-patch:
	${CP} ${WRKSRC}/listen_illumos.go ${WRKSRC}/listen_solaris.go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
