# $NetBSD: Makefile,v 1.7 2026/08/03 09:41:22 adam Exp $

DISTNAME=	zensical-0.0.52
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
DEPENDS+=	${PYPKGPREFIX}-pymdown-extensions>=10.21.3:../../textproc/py-pymdown-extensions
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.2:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.4.0:../../textproc/py-tomli

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
