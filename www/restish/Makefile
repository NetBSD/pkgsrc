# $NetBSD: Makefile,v 1.71 2026/08/31 19:19:11 bsiegert Exp $
#
# Changelog:
# https://github.com/rest-sh/restish/releases/

DISTNAME=	restish-2.3.0
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rest-sh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rest.sh/
COMMENT=	CLI for interacting with REST-ish HTTP APIs
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/example-cli

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
