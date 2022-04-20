# $NetBSD: Makefile,v 1.1 2022/04/20 17:21:28 nia Exp $

DISTNAME=	tree-sitter-0.20.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tree-sitter.github.io/
COMMENT=	Incremental parsing system for programming tools
LICENSE=	mit

USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	tree-sitter.pc.in

.include "../../mk/bsd.pkg.mk"
