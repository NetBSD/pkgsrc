# $NetBSD: Makefile,v 1.10 2019/10/18 14:59:00 bsiegert Exp $

DISTNAME=	parse-2.3.5
PKGNAME=	go-${DISTNAME}
PKGREVISION=	9
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

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
