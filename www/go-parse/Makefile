# $NetBSD: Makefile,v 1.15 2020/03/21 16:57:01 bsiegert Exp $

DISTNAME=	parse-2.3.5
PKGNAME=	go-${DISTNAME}
PKGREVISION=	13
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
