# $NetBSD: Makefile,v 1.17 2025/02/02 17:51:10 wiz Exp $

DISTNAME=	tree-sitter-0.25.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tree-sitter.github.io/
COMMENT=	Incremental parsing system for programming tools
LICENSE=	mit

USE_CC_FEATURES=	c11
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	lib/tree-sitter.pc.in
# for be16toh and friends
# https://github.com/tree-sitter/tree-sitter/issues/4180
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

.include "../../mk/bsd.pkg.mk"
