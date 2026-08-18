# $NetBSD: Makefile,v 1.32 2026/08/18 18:48:17 drixter Exp $

DISTNAME=	resterm-1.2.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=unkn0wn-root/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/unkn0wn-root/resterm/
COMMENT=	Terminal client for HTTP/GraphQL/gRPC
LICENSE=	apache-2.0

USE_LANGUAGES=	c

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
