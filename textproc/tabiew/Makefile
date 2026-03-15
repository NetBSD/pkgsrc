# $NetBSD: Makefile,v 1.5 2026/03/15 13:13:29 wiz Exp $

DISTNAME=	tabiew-0.13.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=shshemi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shshemi/tabiew/
COMMENT=	Lightweight TUI application to view and query tabular data files
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake perl

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
