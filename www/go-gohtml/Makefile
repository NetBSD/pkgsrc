# $NetBSD: Makefile,v 1.22 2020/06/17 09:54:19 bsiegert Exp $

DISTNAME=	gohtml-0.0.20150923
PKGNAME=	go-${DISTNAME}
PKGREVISION=	19
MASTER_SITES=	${MASTER_SITE_GITHUB:=yosssi/}
CATEGORIES=	www
GITHUB_TAG=	ccf383eafddde21dfe37c6191343813822b30e6b
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yosssi/gohtml
COMMENT=	HTML formatter for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/yosssi/gohtml

.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
