# $NetBSD: Makefile,v 1.2 2025/07/27 10:14:09 wiz Exp $

DISTNAME=	tabiew-0.11.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=shshemi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shshemi/tabiew/
COMMENT=	Lightweight TUI application to view and query tabular data files
LICENSE=	mit

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
