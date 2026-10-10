# $NetBSD: Makefile,v 1.3 2026/10/10 20:51:51 wiz Exp $

DISTNAME=	stng-1.7.1
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}archive/
SITES.${DISTNAME}.tar.gz=	-${MASTER_SITES}v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/HEXXDECIMAL/stng/
COMMENT=	Language-aware string extraction for Go and Rust binaries
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${PKGBASE}

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
