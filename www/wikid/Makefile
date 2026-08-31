# $NetBSD: Makefile,v 1.4 2026/08/31 08:42:51 pin Exp $

DISTNAME=	wikid-3.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkthakftw/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sharkthakftw/wikid/
COMMENT=	Feature-rich terminal wikipedia client
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

.include "cargo-depends.mk"

#RUST_REQ=	1.99.0-beta.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.99.0-beta.1 on amd64

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
