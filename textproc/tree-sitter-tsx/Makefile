# $NetBSD: Makefile,v 1.1 2023/06/03 06:37:46 wiz Exp $

DISTNAME=	tree-sitter-typescript-0.20.2
PKGNAME=	${DISTNAME:S/typescript/tsx/}
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tree-sitter/tree-sitter-typescript/
COMMENT=	TSX grammar for tree-sitter
LICENSE=	mit

WRKSRC=			${WRKDIR}/${DISTNAME}
GRAMMAR_SOURCE_DIR=	tsx/src

.include "../../textproc/tree-sitter/grammar.mk"
.include "../../mk/bsd.pkg.mk"
