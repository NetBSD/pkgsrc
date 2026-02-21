# $NetBSD: Makefile,v 1.1 2026/02/21 15:17:28 pin Exp $

DISTNAME=	stng-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}archive/
SITES.${DISTNAME}.tar.gz=	-${MASTER_SITES}v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/HEXXDECIMAL/stng/
COMMENT=	Language-aware string extraction for Go and Rust binaries
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${PKGBASE}

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
