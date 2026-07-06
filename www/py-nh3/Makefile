# $NetBSD: Makefile,v 1.16 2026/07/06 16:56:02 adam Exp $

DISTNAME=	nh3-0.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nh3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/messense/nh3
COMMENT=	Python bindings for Ammonia HTML cleaner
LICENSE=	mit

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
