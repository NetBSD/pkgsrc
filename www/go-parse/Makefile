# $NetBSD: Makefile,v 1.17 2020/04/18 14:18:41 nikita Exp $

DISTNAME=	parse-2.4.2
PKGNAME=	go-${DISTNAME}
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
