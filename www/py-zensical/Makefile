# $NetBSD: Makefile,v 1.3 2026/06/28 15:41:51 wiz Exp $

DISTNAME=	zensical-0.0.45
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zensical/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zensical.org/
COMMENT=	Modern static site generator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../devel/py-maturin
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-deepmerge-[0-9]*:../../devel/py-deepmerge
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pymdown-extensions-[0-9]*:../../textproc/py-pymdown-extensions
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
