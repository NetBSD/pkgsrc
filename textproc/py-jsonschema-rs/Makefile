# $NetBSD: Makefile,v 1.1 2026/11/15 21:44:30 wiz Exp $

DISTNAME=	jsonschema_rs-0.61.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema_rs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Stranger6667/jsonschema/tree/master/crates/jsonschema-py
COMMENT=	High-performance JSON Schema validator for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0:../../devel/py-maturin

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
