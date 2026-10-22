# $NetBSD: Makefile,v 1.71 2026/10/22 17:06:13 drixter Exp $

DISTNAME=	resterm-1.16.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=unkn0wn-root/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/unkn0wn-root/resterm/
COMMENT=	Terminal client for HTTP/GraphQL/gRPC
LICENSE=	apache-2.0

USE_LANGUAGES=	c

post-install:
	${RM} -fv ${DESTDIR}${PREFIX}/bin/capture

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
