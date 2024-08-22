# $NetBSD: Makefile,v 1.6 2024/08/22 13:31:27 wiz Exp $

DISTNAME=	orjson-3.10.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ijl/orjson
COMMENT=	Fast, correct Python JSON library
LICENSE=	apache-2.0 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.7.1:../../devel/py-maturin

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
