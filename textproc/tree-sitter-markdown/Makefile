# $NetBSD: Makefile,v 1.3 2025/04/11 07:50:02 wiz Exp $

DISTNAME=	tree-sitter-markdown-0.4.1
# we switched to from a version that had 0.7.1 as last release to the official one
# so we need to make sure the version number is higher than it was before
PKGNAME=	${DISTNAME:S/markdown-/markdown-0.7.1./}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter-grammars/}
GITHUB_TAG=	v0.3.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tree-sitter-grammars/tree-sitter-markdown
COMMENT=	Markdown grammar for tree-sitter
LICENSE=	mit

GRAMMAR_SOURCE_DIR=	tree-sitter-markdown/src

.include "../../textproc/tree-sitter/grammar.mk"
.include "../../mk/bsd.pkg.mk"
