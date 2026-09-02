# $NetBSD: Makefile,v 1.2 2026/09/02 09:59:29 adam Exp $

DISTNAME=	comrak-0.0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/comrak/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lmmx/comrak
COMMENT=	Python bindings for the Comrak Rust library, a fast CommonMark/GFM parser
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
