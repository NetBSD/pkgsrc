# $NetBSD: Makefile,v 1.1 2023/01/19 12:26:12 wiz Exp $

DISTNAME=	tree-sitter-0.20.7
PKGNAME=	${DISTNAME:S/sitter/sitter-cli/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_PROJECT=	tree-sitter
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tree-sitter.github.io/
COMMENT=	Incremental parsing system for programming tools (CLI)
LICENSE=	mit

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tree-sitter \
		${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
