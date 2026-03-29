# $NetBSD: Makefile,v 1.14 2026/03/29 17:43:10 wiz Exp $

DISTNAME=	nh3-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nh3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/messense/nh3
COMMENT=	Python bindings for Ammonia HTML cleaner
LICENSE=	mit

USE_LANGUAGES=		c

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
