# $NetBSD: Makefile,v 1.2 2023/01/17 21:30:03 wiz Exp $

DISTNAME=	tree-sitter-0.20.7
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
