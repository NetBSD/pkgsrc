# $NetBSD: Makefile,v 1.11 2026/03/17 11:10:18 pin Exp $

DISTNAME=	prose-0.6.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgdavey/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgdavey/prose/
COMMENT=	Reformat text pleasantly
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
