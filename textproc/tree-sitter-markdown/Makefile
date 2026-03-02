# $NetBSD: Makefile,v 1.7 2026/03/02 12:13:33 wiz Exp $

DISTNAME=	tree-sitter-markdown-0.5.3
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter-grammars/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tree-sitter-grammars/tree-sitter-markdown
COMMENT=	Markdown grammar for tree-sitter
LICENSE=	mit

GRAMMAR_SOURCE_DIR=	tree-sitter-markdown/src

.include "../../textproc/tree-sitter/grammar.mk"
.include "../../mk/bsd.pkg.mk"
