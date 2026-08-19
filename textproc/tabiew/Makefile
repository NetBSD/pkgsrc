# $NetBSD: Makefile,v 1.9 2026/08/19 09:44:11 wiz Exp $

DISTNAME=	tabiew-0.14.2
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
