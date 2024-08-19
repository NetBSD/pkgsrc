# $NetBSD: Makefile,v 1.3 2024/08/19 22:01:07 wiz Exp $

DISTNAME=	tree-sitter-typescript-0.20.4
PKGNAME=	${DISTNAME:S/typescript/tsx/}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_PROJECT=	tree-sitter-typescript
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tree-sitter/tree-sitter-typescript/
COMMENT=	TSX grammar for tree-sitter
LICENSE=	mit

WRKSRC=			${WRKDIR}/${DISTNAME}
GRAMMAR_SOURCE_DIR=	tsx/src

.include "../../textproc/tree-sitter/grammar.mk"
.include "../../mk/bsd.pkg.mk"
