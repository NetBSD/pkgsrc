# $NetBSD: Makefile,v 1.7 2024/04/18 09:06:41 wiz Exp $

DISTNAME=	tree-sitter-0.22.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tree-sitter.github.io/
COMMENT=	Incremental parsing system for programming tools
LICENSE=	mit

USE_TOOLS+=	gmake

USE_CC_FEATURES+=	c11
PKGCONFIG_OVERRIDE+=	tree-sitter.pc.in

.include "../../mk/bsd.pkg.mk"
