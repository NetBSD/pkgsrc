# $NetBSD: Makefile,v 1.8 2024/10/22 08:04:51 wiz Exp $

DISTNAME=	orjson-3.10.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ijl/orjson
COMMENT=	Fast, correct Python JSON library
LICENSE=	apache-2.0 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.7.1:../../devel/py-maturin

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
