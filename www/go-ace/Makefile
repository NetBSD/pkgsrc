# $NetBSD: Makefile,v 1.13 2019/05/27 15:18:33 bsiegert Exp $

DISTNAME=	ace-0.0.4b
PKGNAME=	go-${DISTNAME}
PKGREVISION=	10
MASTER_SITES=	${MASTER_SITE_GITHUB:=yosssi/}
CATEGORIES=	www
GITHUB_TAG=	71afeb714739f9d5f7e1849bcd4a0a5938e1a70d
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yosssi/ace
COMMENT=	HTML template engine for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/yosssi/ace

# Avoid a circular dependency on ace-proxy
post-patch:
	${RUN} ${RM} -rf ${WRKSRC}/examples/cache_options

.include "../../www/go-gohtml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
