# $NetBSD: Makefile,v 1.38 2022/02/13 19:24:26 bsiegert Exp $

DISTNAME=	minify-2.9.21
PKGNAME=	go-${DISTNAME}
PKGREVISION=	6
MASTER_SITES=	${MASTER_SITE_GITHUB:=tdewolff/}
CATEGORIES=	www
GITHUB_PROJECT=	minify
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tdewolff/minify
COMMENT=	Command line tool that minifies web formats concurrently
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/mkwinsyscall

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
