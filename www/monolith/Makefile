# $NetBSD: Makefile,v 1.13 2024/09/06 06:18:41 pin Exp $

DISTNAME=	monolith-2.8.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Y2Z/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Y2Z/monolith/
COMMENT=	CLI tool for saving complete web pages as a single HTML file
LICENSE=	cc0-1.0-universal

.include "cargo-depends.mk"

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
