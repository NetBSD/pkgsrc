# $NetBSD: Makefile,v 1.8 2026/10/11 16:02:22 wiz Exp $

DISTNAME=	tree-sitter-0.26.8
PKGNAME=	${DISTNAME:S/sitter/sitter-cli/}
PKGREVISION=	1
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
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
