# $NetBSD: Makefile,v 1.9 2024/04/20 20:34:01 pin Exp $

DISTNAME=	prose-0.4.7
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
