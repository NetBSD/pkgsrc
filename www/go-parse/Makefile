# $NetBSD: Makefile,v 1.28 2021/06/06 12:19:03 bsiegert Exp $

DISTNAME=	parse-2.4.2
PKGNAME=	go-${DISTNAME}
PKGREVISION=	11
MASTER_SITES=	${MASTER_SITE_GITHUB:=tdewolff/}
CATEGORIES=	www
GITHUB_PROJECT=	parse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tdewolff/parse
COMMENT=	Go parsers for web formats
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/tdewolff/parse

post-install:
	find ${DESTDIR}${PREFIX} -name "*.orig" -exec rm \{\} \;

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
