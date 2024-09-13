# $NetBSD: Makefile,v 1.4 2024/09/13 10:01:32 wiz Exp $

DISTNAME=	tree-sitter-php-0.23.2
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tree-sitter/tree-sitter-php/
COMMENT=	PHP grammar for tree-sitter
LICENSE=	mit

GRAMMAR_SOURCE_DIR=	php/src

.include "../../textproc/tree-sitter/grammar.mk"
.include "../../mk/bsd.pkg.mk"
