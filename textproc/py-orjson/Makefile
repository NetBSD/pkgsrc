# $NetBSD: Makefile,v 1.4 2024/07/04 11:00:42 adam Exp $

DISTNAME=	orjson-3.10.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ijl/orjson
COMMENT=	Fast, correct Python JSON library
LICENSE=	apache-2.0 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1:../../devel/py-maturin

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
