# $NetBSD: Makefile,v 1.12 2026/09/08 19:19:41 adam Exp $
#
# Changelog:
# https://github.com/zensical/zensical/releases

DISTNAME=	zensical-0.0.60
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zensical/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zensical.org/
COMMENT=	Modern static site generator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.8:../../devel/py-maturin
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-deepmerge>=2.0:../../devel/py-deepmerge
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.7:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.20:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pymdown-extensions>=11.0:../../textproc/py-pymdown-extensions
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.4.0:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.2:../../textproc/py-yaml

CARGO_GITHUB_CRATES=	zensical zrx 60793b586b9e2e2cc65b8f99c88abeda9545c3f9
SUBST_NOOP_OK.gitcrate=	yes

PY_RENAME_BINARIES=	zensical

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

RUST_REQ=	1.89

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
