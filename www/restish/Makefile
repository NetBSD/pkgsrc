# $NetBSD: Makefile,v 1.72.2.2 2026/11/11 20:32:27 maya Exp $
#
# Changelog:
# https://github.com/rest-sh/restish/releases/

DISTNAME=	restish-2.3.0
PKGREVISION=	7
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
