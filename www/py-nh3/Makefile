# $NetBSD: Makefile,v 1.5 2024/07/14 13:08:07 wiz Exp $

DISTNAME=	nh3-0.2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nh3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/messense/nh3
COMMENT=	Python bindings for Ammonia HTML cleaner
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../devel/py-maturin

USE_LANGUAGES=		c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
