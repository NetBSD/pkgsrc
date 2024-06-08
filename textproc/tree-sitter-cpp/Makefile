# $NetBSD: Makefile,v 1.11 2024/06/08 12:19:30 wiz Exp $

DISTNAME=	tree-sitter-cpp-0.22.2
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tree-sitter/tree-sitter-cpp/
COMMENT=	C++ grammar for tree-sitter
LICENSE=	mit

GRAMMAR_C_STANDARD=	c11
USE_CC_FEATURES=	c11

.include "../../textproc/tree-sitter/grammar.mk"
.include "../../mk/bsd.pkg.mk"
