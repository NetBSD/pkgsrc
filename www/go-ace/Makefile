# $NetBSD: Makefile,v 1.30 2021/01/23 14:23:13 bsiegert Exp $

DISTNAME=	ace-0.0.5
PKGNAME=	go-${DISTNAME}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=yosssi/}
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yosssi/ace
COMMENT=	HTML template engine for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/yosssi/ace

# Avoid a circular dependency on ace-proxy
post-patch:
	${RUN} ${RM} -rf ${WRKSRC}/examples/cache_options

# \todo: switch to go-module.mk
.include "../../www/go-gohtml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
