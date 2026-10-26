# $NetBSD: Makefile,v 1.2 2026/10/26 05:41:08 adam Exp $

DISTNAME=	unicode_segmentation_rs-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unicode-segmentation-rs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WeblateOrg/unicode-segmentation-rs
COMMENT=	Unicode segmentation and width for Python using Rust
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
# Fix for: changing install names or rpaths can't be redone because larger
# updated load commands do not fit.
RUSTFLAGS=	-C link-arg=-Wl,-headerpad_max_install_names
.endif

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
