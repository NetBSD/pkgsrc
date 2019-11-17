# $NetBSD: Makefile,v 1.10.2.1 2019/11/17 08:30:20 spz Exp $

DISTNAME=	go-gogs-client-0.0.20171114
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=gogs/}
GITHUB_TAG=	5898069c37e1044229e3853adba654d61e45816b

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/gogs/go-gogs-client
COMMENT=	Gogs API client in Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/gogs/go-gogs-client

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
